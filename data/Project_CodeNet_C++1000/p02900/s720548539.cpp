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
#define print(a); for(auto x:a)cout<<x*2<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll a,b;cin>>a>>b;a=__gcd(a,b);
    ll cnt=1;
    for(ll i=2;i*i<=a;i++){
        bool state=0;
        while(a%i==0){state=1;a/=i;}
        if(state)cnt++;
    }
    if(a>1)cnt++;
    cout<<cnt<<"\n";
}
