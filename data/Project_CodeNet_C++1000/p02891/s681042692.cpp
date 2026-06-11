#include<bits/stdc++.h>
#define ll long long int
#define loop(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define pb push_back
#define lim 2750131
using namespace std;
int main()
{ll i,ans=0,k;
	char s[101];
	cin>>s;
	cin>>k;
    vector<ll> v;
	ll n=strlen(s);
    ll curr=1;
	loop(i,1,n)
	{if(s[i]!=s[i-1])
		{v.pb(curr);
			curr=1;}
			else
				curr++;}
			v.pb(curr);
          if(v.size()==1)
          ans=(k*n)/2;else{
			loop(i,0,v.size())
			ans+=v[i]/2;
			ans*=k;
			if(s[0]==s[n-1] && (v[0]*v.back())%2)
				ans+=k-1;}
			cout<<ans<<endl;
			return 0;
}