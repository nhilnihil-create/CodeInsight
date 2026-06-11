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

const ll N=1e5+5;
vector<vi>v(N);
bool vst[N];
ll color[N];
ll n,mx;

void dfs(ll a){
    ll cnt=1;
    for(auto u:v[a]){
        if(vst[u])continue;
        if(cnt==color[a])cnt++;
        color[u]=cnt++;
        vst[u]=true;
        dfs(u);
    }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    vi vv;
    for(int i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
        vv.pb(b);
    }
    color[1]=0;vst[1]=1;
    dfs(1);
    ll ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,color[i]);
    cout<<ans<<"\n";
    for(int i=0;i<vv.size();i++)cout<<color[vv[i]]<<"\n";
}
