#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
#define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;

signed main() {
    int n;
    string s;
    cin >> n >>s;
    int ans = 0;
    rep(i,10) {
        rep(j,10) {
            rep(k,10) {
                int now = i;
                int cnt = 0;
                    
                rep(l,n) {
                    //cout << s[l] << endl;
                    if((int)(s[l]-'0')==now) {
                        cnt++;
                        if(cnt==3) {
                            ans++;
                            break;
                        }
                        if(cnt==1)now=j;
                        else now=k;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

