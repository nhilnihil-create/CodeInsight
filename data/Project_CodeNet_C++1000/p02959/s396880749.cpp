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
    ll a[n+1];
    ll sum=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll he[n];
    for(int i=0;i<n;i++){
        cin>>he[i];
    }
    for(int i=0;i<n;i++){
        if(he[i]<=a[i])a[i]-=he[i];
        else{
            he[i]-=a[i];
            a[i+1]=max(0ll,a[i+1]-he[i]);
            a[i]=0;
        }
    }
    for(int i=0;i<=n;i++){
        sum-=max(0ll,a[i]);
    }
    cout<<sum<<"\n";
}
