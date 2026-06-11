#include<bits/stdc++.h>
using namespace std;
typedef  long long ll; 

ll inf =1e9+7;

#define pi 3.14159265358979323846L
bool isprime(ll a)
{
	
	ll cnt=0;	
	for(ll i=1;i*i<a;i++)
	{
		
	 	if(a%i==0)
	 	{
	 		cnt+=2;
		 }
		
		
	}
	
		if(cnt==2)
		return true;
		else
		return false;
		
}
ll mod(ll a)
{
	if(a<inf)return a;
	else
	return a%inf;
}
void solve()
{

string s,t;
cin>>s>>t;
if(s==t.substr(0,s.size()) &&t.size()==s.size()+1)
{
	cout<<"Yes";
	
}
else
cout<<"No";
}

int main()
{


ios::sync_with_stdio(0); 
	cin.tie(0);

		solve();
	
return 0;

		
	}
	
	
	
