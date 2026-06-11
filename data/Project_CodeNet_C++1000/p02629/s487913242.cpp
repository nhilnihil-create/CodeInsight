#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll m=1000000007;

int main()
{
	fast;
	map<int,char>m;
	for(int i=0;i<26;i++)
		m[(i+1)%26]=(char)(97+i);
	ll n;cin>>n;
	stack<char>s;
	while(n>0)
	{
		int rem=n%26;
		s.push(m[rem]);
		if(rem)
			n-=rem;
		else
			n-=26;
		n/=26;
	}
	while(!s.empty())
	{
		cout<<s.top();
		s.pop();
	}
}