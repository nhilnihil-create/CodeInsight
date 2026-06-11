#include<bits/stdc++.h>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ll long long
//不要再爆long long了！！！！！！！！不要再爆long long了！！！！！！！ 

int main()
{
	ll a,va,b,vb,t;
	cin>>a>>va>>b>>vb>>t;
	cout<<((va*t>=abs(a-b)+vb*t)?("YES"):("NO"));
	return 0;
}