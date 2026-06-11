#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 ,-1};
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
signed main(){
    int X,Y;
    cin >> X >> Y;
    if((X+Y)%3 != 0 || Y*2 < X || X*2 < Y) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = (X+Y)/3;
    int cnt2 = min(Y-cnt,X-cnt);
    int sum = 1;
    for(int i = cnt; i > cnt-cnt2; i--) {
        sum*=i;
        sum%=mod;
    }
    for(int i = 1; i <= cnt2; i++) {
        sum *= mod_pow(i,mod-2);
        sum %= mod;
    }
    cout << sum << endl;
}
