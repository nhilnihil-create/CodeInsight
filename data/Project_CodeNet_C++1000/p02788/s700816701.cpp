#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,d,a;
    cin>>n>>d>>a;
    vector<pair<ll,ll>> vec(n);
    for(ll i=0;i<n;++i)
    {
    	ll a,b;
    	cin>>a>>b;
    	vec[i]=make_pair(a,b);

    }

    sort(vec.begin(),vec.end());

    long long ans=0;
    set<pair<ll,ll> >s;
    long long sum=0;
    for(ll i=0;i<n;++i)
    {
    	auto it1=s.lower_bound(make_pair(vec[i].first,-1));
    	auto it2=s.rbegin();
    	ll y=0;
    	if(it1!=s.end()&&s.size()>=1)
    	{
    	    if(it1!=s.begin())
    	    {
    	        it1--;
    	        ll start=it1->second;
    	        ll end=it2->second;
    	        y=end-start;
    	    }
    	    else
    	    {
    	        y=it2->second;
    	    }
    	}
    	
    	ll right=vec[i].first+2*d;
    	long double temp=0.0;
    	if(vec[i].second>=y)
    	temp=(vec[i].second-y)/(long double)a;
    	ll res=ceil(temp);
    	ans+=res;

    	sum+=res*a;
    	s.insert(make_pair(right,sum));
    	

    }

    cout<<ans<<endl;



}
