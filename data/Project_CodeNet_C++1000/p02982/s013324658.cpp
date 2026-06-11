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
    ll n,d;cin>>n>>d;
    vector<vi>v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            ll a;cin>>a;
            v[i].pb(a);
        }
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<i+n;k++){
            ll sum=0;
            for(int j=0;j<d;j++){
                ll a=v[i][j]-v[(k)%n][j];
                sum+=(a*a);
            }
            ll t=(ll)sqrt((ld)sum);
            if(sqrt((ld)sum)==t)cnt++;
        }
    }
    cout<<cnt/2<<"\n";
}
