#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "test"
using namespace std;
const ll N = 100 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;
ll dx[2] = {0,1};
ll dy[2] = {1,0};
ll dp1[N][N],dp2[N][N];
ll n,m,i,j;
char a[N][N];
bool chk(ll x,ll y){
    return (x <= n&&y <= m);
}
ll f1(ll x,ll y){
    if (x == n&&y == m) return 0;
    if (dp1[x][y] != -1) return dp1[x][y];
    ll ans = inf;
    for (ll i = 0;i < 2;i++){
        ll p = x + dx[i],q = y + dy[i];
        if (chk(p,q)){
            if (a[p][q] == a[x][y]) ans = min(ans,f1(p,q));
            else{
                if (a[p][q] == '#') ans = min(ans,1 + f1(p,q));
                else ans = min(ans,f1(p,q));
            }
        }
    }
    return dp1[x][y] = ans;
}
ll f2(ll x,ll y){
    if (x == n&&y == m) return 0;
    if (dp2[x][y] != -1) return dp2[x][y];
    ll ans = inf;
    for (ll i = 0;i < 2;i++){
        ll p = x + dx[i],q = y + dy[i];
        if (chk(p,q)){
            if (a[p][q] == a[x][y]) ans = min(ans,f2(p,q));
            else{
                if (a[p][q] == '.') ans = min(ans,1 + f2(p,q));
                else ans = min(ans,f2(p,q));
            }
        }
    }
    return dp2[x][y] = ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin>>n>>m;
    for (i = 1;i <= n;i++){
        for (j = 1;j <= m;j++) cin>>a[i][j];
    }
    memset(dp1,-1,sizeof(dp1)); memset(dp2,-1,sizeof(dp2));
    ll p = f1(1,1),q = f2(1,1); q++;
    if (a[1][1] == '#') p++;
    else q++;
    cout<<min(p,q);
}
