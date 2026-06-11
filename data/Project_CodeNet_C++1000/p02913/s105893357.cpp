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

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    string s;cin>>s;
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll t=0;
        for(int j=0;j<n-i;j++){
            t=(t+1)*(s[j]==s[j+i]);
            ans=max(ans,min(i,t));
        }
    }
    cout<<ans<<"\n";
}
