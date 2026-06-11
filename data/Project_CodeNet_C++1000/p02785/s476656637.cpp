#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    
    vector<int> a(n);
    rep(i,n) {
    cin >> a.at(i);
    }
    
    sort(a.begin(),a.end());
    
    
    if(k >= n) {
    cout << 0;
    }
    else {
        rep(i,k) {
        a.pop_back();
        }
        
        long long sum = 0;
        rep(i, n-k) {
        sum += a.at(i);
        }
        cout << sum;
     }
    
}