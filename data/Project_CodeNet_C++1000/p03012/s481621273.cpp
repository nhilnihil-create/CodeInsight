#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int  n; cin >> n;
    int a[n], pre[n]={}; for(int &i : a) cin >> i;
    for(int  i= 0; i < n; i++) {
        if(i) pre[i] = pre[i-1];
        pre[i] += a[i];
    }    

    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        int res=0;
        res += pre[n-1] - pre[i];
        res -= pre[i];
        ans = min(ans, abs(res)); 
    }
    cout << ans;
}