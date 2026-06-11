#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mod_pow(int x,int y) {
    int res = 1;
    while(y > 0) {
        if(y%2) {
            res = res*x%mod;
        }
        x = x*x%mod;
        y/=2;
    }
    return res;
}
signed main() {
    int n,a,b;
    cin >> n >> a >> b;
    int ans = mod_pow(2,n)-1;
    int cnt = 1;
    for(int i = n; i >= n-a+1; i--) {
        cnt *= i;
        cnt %= mod;
    }
    for(int i = 1; i <= a; i++) {
        cnt = cnt*mod_pow(i,mod-2)%mod;
    }
    ans = (ans+mod-cnt)%mod;
    cnt = 1;
       for(int i = n; i >= n-b+1; i--) {
           cnt *= i;
           cnt %= mod;
       }
       for(int i = 1; i <= b; i++) {
           cnt = cnt*mod_pow(i,mod-2)%mod;
       }
       ans = (ans+mod-cnt)%mod;
    cout << ans << endl;
}
