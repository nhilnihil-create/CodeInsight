#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)
#define mod 1000000007
#define mad(a,b) a=(a+b)%mod
#define N 1000000

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    set<ll> st;
    ll n;
    pair<ll,ll> p[100010];
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>p[i].first;
	p[i].second=i;
    }
    sort(p,p+n,greater<pair<ll,ll> >());
    st.insert(-1);st.insert(-2);
    st.insert(n); st.insert(n+1);
    ll ans=0;
    for(int i=0;i<n;i++){
	ll x=p[i].second;
	ll a,b,c,d;
	auto it=st.lower_bound(x);
	c=*it; it++; d=*it; it--; it--; chmin(d,n);
	b=*it; it--; a=*it; chmax(a,(ll)-1);
	ll cnt=0;
	cnt+=(x-b)*(d-c);
	cnt+=(b-a)*(c-x);
	ans+=p[i].first*cnt;
	st.insert(x);
    }
    cout<<ans<<endl;
}

