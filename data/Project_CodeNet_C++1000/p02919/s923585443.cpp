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

const ll N=100005ll;
ll l[N],r[N],p[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll d;
    for(int i=1;i<=n;i++){
        cin>>d;
        p[d]=i;
        l[i]=i-1;
        r[i]=i+1;
    }
    ll ans=0;
    for(int i=1;i<n;i++){
        ll a=l[p[i]];
        ll b=l[a];
        ll c=r[p[i]];
        ll d=r[c];
        if(a!=0)ans+=(a-b)*(c-p[i])*i;
        if(c!=n+1)ans+=(d-c)*(p[i]-a)*i;
        l[c]=a;
        r[a]=c;
    }
    cout<<ans<<"\n";
}

