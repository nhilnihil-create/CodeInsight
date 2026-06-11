#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,t;
    cin>>n>>t;
    ll a,b;
    vector<pair<ll,ll> > v;
    for(int i=0;i<n;i++){
    	cin>>a>>b;
    	v.push_back({a,b});
    }
    sort(be(v));
    ll dp[t+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
    	a=v[i].first;
    	b=v[i].second;
    	for(int j=t-1;j>=0;j--){
    		dp[min(t,j+a)]=max(dp[min(t,j+a)],dp[j]+b);
    	}
    }
    cout << dp[t] <<endl;
    return 0;
}
