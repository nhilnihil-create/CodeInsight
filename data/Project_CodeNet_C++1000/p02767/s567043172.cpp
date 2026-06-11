#include<bits/stdc++.h>

using namespace std;

int get(vector<int> &a, int x) {
    int res = 0;
    for(int i : a) {
        res += (x - i) * (x - i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int s = 0;
    int x;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        s += x;
        a.push_back(x);
    }
    int res = -1;
    int resV = 1e9;
    int div = s / n;
    for(int i = div - 1; i <= div + 1; ++i) {
        if(i >= 0) {
            if(get(a, i) < resV) {
                resV = get(a, i);
                res = i;
            }
        }
    }
    cout << resV << endl;
    return 0;
}