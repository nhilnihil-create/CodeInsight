#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

const ll N=2e5+5;
ll n,q;
vector<vi>v(N);
ll val[N];

void dfs(ll a,ll b){
    val[a]+=val[b];
    for(auto x:v[a]){
        if(x!=b)dfs(x,a);
    }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    mset(val);
    for(int i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        v[a].pb(b);v[b].pb(a);
    }
    for(int i=0;i<q;i++){
        ll a,b;cin>>a>>b;
        val[a]+=b;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)cout<<val[i]<<" ";
}
