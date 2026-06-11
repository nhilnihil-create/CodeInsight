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
	//ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll a[n+1];
    ll dp[n+1];mset(dp);
    vi ans;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--){
        ll cnt=0;
        for(int j=i;j<=n;j+=i){
            cnt+=dp[j];
        }
        if(cnt%2!=a[i]){dp[i]=1;ans.pb(i);}
    }
    cout<<ans.size()<<"\n";
    print(ans);
}
