#include<bits/stdc++.h>
#define ll long long
#define yes cout<<"Yes"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define mod 1000000007
#define f first
#define sec second
#define gcd(x,y) __gcd(x, y)
using namespace std;
int main()
{
	ll a,b;
	cin>>a>>b;
	if(b==1)
	{
		cout<<0<<endl;
		return 0;
	}
	ll x=0,y=1;
	while(y<b)
	{
		y+=a-1;
		x++;
	}
	
	cout<<x<<endl;
}