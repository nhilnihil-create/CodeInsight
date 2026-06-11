#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "test"
using namespace std;
const ll N = 1e5 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;

string s;
ll n,i,dp[N][2],k;
ll f(ll pos,ll prv){
    if (pos < 1) return 0;
    if (dp[pos][prv] != -1) return dp[pos][prv];
    ll ans;
    if (prv == 1) ans = min(1 + f(pos - 1,1),f(pos - 1,0));
    else{
        if (s[pos] == s[pos + 1]) ans = 1 + f(pos - 1,1);
        else ans = min(1 + f(pos - 1,1),f(pos - 1,0));
    }
    return dp[pos][prv] = ans;
}
ll Count1(){
    ll res = 0;
    for (i = 1;i <= n;i++){
        if (s[i] == s[1]) res++;
        else break;
    }
    return res;
}
ll Count2(){
    ll res = 0;
    for (i = n;i >= 1;i--){
        if (s[i] == s[n]) res++;
        else break;
    }
    return res;
}
bool chkcond(){
    for (i = 2;i <= n;i++) if (s[i] != s[i - 1]) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>s>>k; n = s.size(); s = " " + s;
    memset(dp,-1,sizeof(dp));
    if (chkcond()){
        cout<<(n*k)/2; return 0;
    }
    ll p = min(f(n - 1,1) + 1,f(n - 1,0)),ans;
    //cout<<f(n - 1,1) + 1<<"\n";
    if (f(n - 1,1) + 1 == p) ans = p*k;
    else{
        if (s[1] == s[n]){
            ll x = Count1(),y = Count2();
            ans = p*k - (x/2 + y/2 - (x + y)/2)*(k - 1);
        }
        else ans = p*k;
    }
    ll q = k/2;
    cout<<ans;
}
