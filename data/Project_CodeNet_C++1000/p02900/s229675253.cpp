#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


vector<int> prime_division(ll x)
{
	vector<int> ret;
	Rep(i,2,sqrt(x)+1)
	{
		while(x%i==0)
		{
			ret.emplace_back(i);
			x/=i;
		}
	}
	if(x!=1) ret.emplace_back(x);
	return ret;
}
int main()
{
	ll A,B;
	cin>>A>>B;
	vector<int> p_a=prime_division(A);
	map<int,int> m_a;
	for(int a : p_a)
	{
		m_a[a]=1;
	}
	vector<int> p_b=prime_division(B);
	map<int,int> m_b;
	for(int b : p_b)
	{
		m_b[b]=1;
	}	
	int ans=1;
	for(auto p : m_a)
	{
		ans+=m_b[p.first];
	}
	cout<<ans<<endl;
	return 0;
}
