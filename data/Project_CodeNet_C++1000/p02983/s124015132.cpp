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
ll MOD=2019;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll l,r;cin>>l>>r;
    ll ans=INF;
    for(int i=l;i<l+2020;i++)for(int j=r;j>r-2020;j--){
        if(j<=i)break;
        ans=min(ans,(ll)i%2019*j%2019);
    }
    cout<<ans<<"\n";
}
