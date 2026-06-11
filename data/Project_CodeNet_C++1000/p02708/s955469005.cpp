#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000
#define mod 1000000007

using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = k; i <= n+1; i++){
        int mx = (n-i)*i+i*(i+1)/2;
        int mn = i*(i-1)/2;
        ans += mx-mn+1;
        ans %= mod;
    }
    cout << ans << endl;
}





















