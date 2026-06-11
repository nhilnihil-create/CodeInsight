#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);
//const ll mod = 998244353;

vector<ll> dp(440000);

int main(void)
{
    string s;
    ll k;
    cin >> s >> k;
    ll ans=0, n = s.size(), p=0;
    vector<ll> cnt(n+1, 0);
    char tmp = s[0];
    rep(i,n){
        if(s[i] == tmp) cnt[p]++;
        else{
            p++;
            cnt[p]++;
            tmp = s[i];
        }
    }
    if(p == 0) ans = n*k/2;
    else{
        rep(i,p+1) ans += cnt[i]/2;
        ans *= k;
        if(s[0] == s[n-1]){
            ans -= (cnt[0]/2 + cnt[p]/2 - (cnt[0] + cnt[p]) / 2) * (k-1);
        }
    }
    cout << ans << endl;
    return 0;
}
