#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll m,n,t,x,y; 

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>t;
    if(t==1000000000000000000) cout<<0<<" "<<1000000000<<" "<<1000000000<<" "<<0<<" "<<0<<" "<<0;
    else if(t<=1e9) cout<<0<<" "<<0<<" "<<0<<" "<<t<<" "<<1<<" "<<0;
    else
    {
    	ll a=t/1000000000;
    	a++;
    	ll c=a*1000000000-t;
    	cout<<0<<" "<<0<<" "<<a<<" "<<1<<" "<<c<<" "<<1000000000;
	}
	return 0;
}