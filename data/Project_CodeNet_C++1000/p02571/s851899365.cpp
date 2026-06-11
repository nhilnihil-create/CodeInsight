#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(z) (z).begin(),(z).end() 
#define MOD 1000000007
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll isprime(ll n)
{
	for(int i=2;i<n;i++)
		if(n%i==0)
		return 0;
		
	return 1;	
}
int main()
{ 
    FAST;
	string s,t;
	cin>>s;
	cin>>t;
	ll s1=s.size();
	ll t1=t.size();
	ll m=INT_MAX;
	for(int i=0;i<s1-t1+1;i++)
	{
		ll tmp=0;
		ll cnt=0;
		for(int j=0;j<t1;j++)
		{
			//cout<<t[j]<<" "<<s[i+tmp]<<endl;
			if(t[j]==s[i+tmp])cnt++;
			tmp++;
		}
		//cout<<cnt<<endl;
		m=min(m,t1-cnt);
	}
	cout<<m;
	
}
