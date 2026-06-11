#include <vector>
#include <iostream>
using namespace std;

int n, *d;
int cnt = 0;

void sort(int length){
    for(int i = 0; i < length; i++){
        for(int k = i + length; k < n; k += length){
            int now = d[k];
            int m = k - length;
            for(; m >= 0; m -= length){
                d[m + length] = d[m];
                if(d[m] <= now) break;
                cnt++;
            }
            d[m + length] = now;
        }
    }
}

int main() {
    cin >> n;
    d = new int[n];
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    
    vector<int> v;
    for(int i = 1; i <= n; i = 3*i + 1) v.push_back(i);
    
    
    cout << v.size() << endl;
    for(long i = v.size()-1; i  >= 0; i--){
        sort(v[i]);
        cout << (i == v.size()-1 ? "" : " ") << v[i];
    }
    cout << endl << cnt << endl;
    
    for(int i = 0; i < n; i++){
        cout << (!i ? "" : "\n") << d[i];
    }
    cout << endl;
    
    return 0;
}