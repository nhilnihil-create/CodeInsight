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
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    ll cnt=0;
    for(int i=0;i<n-1;i++)if(s[i]!=s[i+1])cnt++;
    cout<<n-1-max(cnt-2*k,0ll)<<"\n";
}
