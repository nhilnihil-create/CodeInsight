#include<bits/stdc++.h>
using namespace std;


int main()
{
	typedef long long ll;
	
	ll a,v;  cin>>a>>v;
	ll b,w;  cin>>b>>w;
	ll t;  cin>>t;
	
	ll s=abs(a-b);
	ll s1=(v-w)*t;
	
	if(s<=s1)
	  cout<<"YES"<<endl;
	
	else 
	cout<<"NO"<<endl;

  return 0;
}
