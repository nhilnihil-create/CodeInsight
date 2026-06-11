#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{ 
    fast;
    ll n;
    cin>>n;

    ll p[n],x,ans=0;
    for(ll i=0;i<n;i++)
    	{
    		cin>>x;
    		x--;
    		p[x]=i;
    	}
    
  multiset<ll> s;
  s.insert(-1);
  s.insert(-1);
  s.insert(n);
  s.insert(n);

  for(ll i=n-1;i>=0;i--)
  {
  	s.insert(p[i]);
    auto it=s.find(p[i]);

    it--;
   ll a=*(it);
    it--;
    ll b=*(it);
    it++;
    it++;
    it++;
    ll x=*(it);
    it++;
    ll y=*(it);

  	ans=ans+((a-b)*(x-p[i]) +(p[i]-a)*(y-x))*(i+1);
  }
  cout<<ans<<endl;
}
