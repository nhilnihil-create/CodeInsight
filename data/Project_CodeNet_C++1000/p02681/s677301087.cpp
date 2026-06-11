#include<bits/stdc++.h>
const int M=1e9+7;// M=1e9+7;//M=300000;//
const int N=2e6+5;
typedef long long int ll;
using namespace std;
 
ll cnt(0),sum(0),n,x,y,t,i,j,temp,k,ans(0),mn(M),mx(-9e9);
ll table[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s,p;
	cin>>s>>p;
	for(i=0;i<s.size();i++)
	{
		if(s[i]!=p[i])
		{
			break;
		}
	}
	cout<<(i==s.size()?"Yes":"No");
}