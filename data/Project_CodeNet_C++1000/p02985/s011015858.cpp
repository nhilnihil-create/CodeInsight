#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
ll n,k;
ll ans;
vector<vector<ll> > v(100000);
bool niko[100000];
void dfs(ll a){
    ll maki=v[a].size();
    niko[a]=true;
    if(a){
        for(ll i=k-2,j=1;j<maki;j++,i--){
            ans*=i;
            ans%=mod;
        }
    }else{
        for(ll i=k-1,j=0;j<maki;j++,i--){
            ans*=i;
            ans%=mod;
        }
    }
    for(ll i=0;i<maki;i++){
        if(niko[v[a][i]]==0){
            dfs(v[a][i]);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    memset(niko,0,sizeof(niko));
    ans=k;
    ll a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(0);
    cout << ((ans%mod)+mod)%mod<<endl;
    return 0;
}
