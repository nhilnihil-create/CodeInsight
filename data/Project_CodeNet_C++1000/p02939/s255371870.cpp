#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 2e5 + 9;
const ll inf = 1e6 + 7;
typedef pair<ll,ll> LL;

string s;
ll n,i,dp[3][N];
bool chk(ll pos){
    string p = s.substr(pos,2),q = s.substr(pos - 2,2);
    return (p != q);
}
ll f(ll past,ll pos){
    if (pos > n) return 0;
    if (dp[past][pos] != -1) return dp[past][pos];
    ll ans = 0;
    if (past == 1){
        if (n - pos + 1 > 1) ans = max(ans,1 + f(2,pos + 2));
        if (s[pos] != s[pos - 1]) ans = max(ans,1 + f(1,pos + 1));
    }
    else{
        ans = max(ans,1 + f(1,pos + 1));
        if (n - pos + 1 > 1&&chk(pos)) ans = max(ans,1 + f(2,pos + 2));
    }
    return dp[past][pos] = ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin>>s; n = s.size(); s = " " + s;
    memset(dp,-1,sizeof(dp));
    cout<<max(f(1,2),f(2,3)) + 1;
}
