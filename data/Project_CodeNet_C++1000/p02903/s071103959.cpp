#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 1e3 + 9;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> LL;

ll n,m,a,b,ans[N][N];
void Fill(ll x,ll y,ll p,ll q){
    ll i,j;
    //cout<<x<<" "<<y<<" "<<p<<" "<<q<<"\n";
    for (i = x;i <= p;i++){
        for (j = y;j <= q;j++) ans[i][j] = 1;
    }
}
void out(){
    for (ll i = 1;i <= n;i++){
        for (ll j = 1;j <= m;j++) cout<<ans[i][j];
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>n>>m>>a>>b;
    ll q = m - a,p = n - b;
    ll curx = 1,cury = 1;
    while(curx <= n&&cury <= m){
        ll x = min(n,curx + p - 1),y = min(m,cury + q - 1);
        //cout<<x<<" "<<y; return 0;
        Fill(curx,cury,x,y);
        //out(); return 0;
        curx = x + 1,cury = y + 1;
    }
    out();
}

