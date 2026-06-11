#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    LL n; cin >> n; LL a[n]; for(LL &i : a) cin >> i;
    bool b = 1; LL last=a[n-1]; 
    for(int i = 0; i < n-1; i++) {
        if(b) last -= a[i];
        else last += a[i];
        b ^= 1;
    }    
    LL ans[n]; ans[n-1] = last;
    for(int i = n - 2; i >= 0; i--) {
        ans[i] = a[i] * 2LL - ans[i+1];
    }
    for(auto x : ans) cout << x << " ";
}