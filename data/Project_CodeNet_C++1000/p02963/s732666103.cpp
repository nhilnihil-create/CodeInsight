#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
ll m,n,a,b,c=1,d=1e9,e;

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
	cin>>m;
	if(m<=1000000000) cout<<0<<" "<<0<<" "<<0<<" "<<1<<" "<<m<<" "<<0;
	else if(m==1000000000000000000) cout<<0<<" "<<0<<" "<<1000000000<<" "<<0<<" "<<0<<" "<<1000000000; 
	else
	{
		n=m/1000000000;
		a=m/1000000000+1;
		b=a*1000000000-m;
		cout<<0<<" "<<0<<" "<<a<<" "<<b<<" "<<1<<" "<<1000000000;
	}
	return 0;
}
