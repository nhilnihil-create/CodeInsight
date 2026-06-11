#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = s.length();
    vector<vector<ll> > dp(n+1, vector<ll> (13, 0));
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        if(s[i] == '?'){
            for(int j=0;j<13;j++){
                for(int num = 0; num < 10;num++)
                    (dp[i+1][(j*10+num) % 13] += dp[i][j]) %= mod;
            }
        }else{
            ll num = s[i] - '0';
            for(int j=0;j<13;j++){
                (dp[i+1][(j*10+num) % 13] += dp[i][j]) %= mod;
            }
        }
    }
    cout << dp[n][5] << endl;
    return 0;
}
