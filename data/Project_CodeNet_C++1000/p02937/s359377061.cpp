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
    string s,t;cin>>s>>t;
    vector<vi>v(26);
    for(int i=0;i<s.size();i++){
        v[s[i]-'a'].pb(i);
    }
    ll x=0,ans=0;
    for(int i=0;i<t.size();i++){
        ll val=t[i]-'a';
        if(v[val].empty()){ans=-1;break;}
        auto y=lower_bound(all(v[val]),x);
        if(y==v[val].end()){ans+=(s.size()-x);x=0;y=lower_bound(all(v[val]),0);}
        ans+=*y-x+1;
        x=*y+1;
    }
    cout<<ans<<"\n";
}
