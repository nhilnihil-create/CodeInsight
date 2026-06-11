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
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll b[n];
    for(int i=0;i<n;i++)cin>>b[i];
    ll c[n-1];
    for(int i=0;i<n-1;i++)cin>>c[i];
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=b[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]==a[i]+1)sum+=c[a[i]-1];
    }
    cout<<sum<<"\n";
}
