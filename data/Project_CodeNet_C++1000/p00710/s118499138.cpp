#include<iostream>
#include<vector>
#include<algorithm> 
#include<iterator> 

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void initStatus(vector<int> &v) {
    int size = v.size();
    for (int i = 0; i < size; i ++) {
        v[i] = size - i;
    }
}

vector<int> change(vector<int> &v, int n, int p, int c) {
    vector<int> v1(p - 1);
    vector<int> v2(c);
    vector<int> v3(n - (p - 1) - c);

    int count_v1 = 0;
    int count_v2 = 0;
    int count_v3 = 0;

    for (int i = 0; i < n; i ++) {
        if (i < p - 1) {
           v1[count_v1] = v[i]; 
           count_v1 ++;
        } else if (i > p + c - 2) {
            v3[count_v3] = v[i];
            count_v3 ++;
        } else {
            v2[count_v2] = v[i];
            count_v2 ++;
        }
    }
        std::copy(v1.begin(),v1.end(),std::back_inserter(v2));
        std::copy(v3.begin(),v3.end(),std::back_inserter(v2));
    return v2;
}

int shuffle(vector<int> &v, int n, int r) {
    int p;
    int c;
    for (int i = 0; i < r; i ++) {
        cin >> p >> c; 
        v = change(v, n, p, c);
    }
}

int main() {
    int n;
    int r;
    cin >> n >> r; 
    while (n != 0 && r != 0) {
        vector<int> v(n);
        initStatus(v);
        shuffle(v, n, r);
        cout << v[0] << endl;
        cin >> n >> r; 
    }
    return 0;
}