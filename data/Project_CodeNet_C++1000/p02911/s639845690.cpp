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
    ll n,k,q;cin>>n>>k>>q;
    ll s[n];mset(s);
    for(int i=0;i<q;i++){
        ll d;cin>>d;d--;
        s[d]++;
    }
    for(int i=0;i<n;i++){
        if(s[i]+k-q<=0)cout<<"No\n";
        else cout<<"Yes\n";
    }
}
