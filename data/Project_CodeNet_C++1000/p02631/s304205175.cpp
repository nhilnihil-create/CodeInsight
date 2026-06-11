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

	ll int tc=1;
	while(tc--)
	{
		ll int n;
		cin>>n;
		vector<ll int> v;
		ll int x;
		ll int s=0;
		//ll int flag=0;
		for(ll int i=0;i<n;i++)
		{
			cin>>x;
			s^=x;
			v.push_back(x);

		}
		for(int i=0;i<n;i++)
		{
			int x=s^v[i];
			
		cout<< x <<" ";
		}
		cout<<endl;
		

	}
}


