#include<bits/stdc++.h>
#define MOD 1000000007
#define mp make_pair
#define ll long long
#define pb push_back
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug cout<<"Debugging.."<<endl
using namespace std;
int main()
{
	faster;

	int a,b,c,k;
	cin>>a>>b>>c>>k;
	int sum=0;
	if(k>=a)
	{
		sum+=a;
		k=k-a;
	}
	else
	{
		sum+=k;
		k=0;
	}
	if(k>=b)
	k=k-b;
	else
	k=0;
	if(k>=c)
	{
		sum-=c;
		k=k-c;
	}
	else
	{
		sum-=k;
		k=0;
	}
	
		cout<<sum<<endl;

}


