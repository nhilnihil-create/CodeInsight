#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define INF 9223372036854775807
const ll mod=998244353;

vector<vector<ll>> v;
ll n,m,q,ans=0;

void check(vector<ll> &a){
    ll c=0;
    //for(ll i=0;i<a.size();i++)
    //    cout<<a[i]<<" ";
    for(ll i=0;i<v.size();i++){
        if(a[v[i][1]-1]-a[v[i][0]-1]==v[i][2]){
            c+=v[i][3];
            //cout<<i<<",";
        }
    }
    //cout<<"\n";
    ans=max(ans,c);
}

void solve(ll pos,ll st,vector<ll> a){
    a.pb(st);
    if(pos==n-1){
        check(a);
        return;
    }
    for(ll i=st;i<=m;i++)
        solve(pos+1,i,a);
    return;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m>>q;
    while(q--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        v.pb({a,b,c,d});
    }
    vector<ll> p;
    for(ll i=1;i<=m;i++){
        solve(0,i,p);
    }
    cout<<ans;

    
    return 0;
}