#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fs first
#define sc second
#define task "tst"
using namespace std;
const ll N = 3e5 + 9;
const ll inf = 1e9 + 7;
typedef pair<ll,ll> LL;

ll x,y,a,b,c,R[N],G[N],C[N],i,j;
vector<ll> res;
bool lf(ll x,ll y){
    return x > y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin>>x>>y>>a>>b>>c;
    for (i = 1;i <= a;i++) cin>>R[i]; sort(R + 1,R + a + 1,lf);
    for (i = 1;i <= b;i++) cin>>G[i]; sort(G + 1,G + b + 1,lf);
    for (i = 1;i <= c;i++) cin>>C[i]; sort(C + 1,C + c + 1,lf);
    for (i = 1;i <= x;i++) res.push_back(R[i]);
    for (i = 1;i <= y;i++) res.push_back(G[i]);
    sort(res.begin(),res.end(),lf);
    //for (auto i : res) cout<<i<<" "; return 0;
    i = res.size() - 1; j = 1;
    while(true){
        if (i < 0||C[j] <= res[i]) break;
        res[i] = C[j];
        j++; i--;
    }
    ll sum = 0;
    for (auto i : res) sum += i;
    cout<<sum;
}
