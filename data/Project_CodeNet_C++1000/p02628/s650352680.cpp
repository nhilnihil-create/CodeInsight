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
		ll int n,k;
		cin>>n>>k;
		vector<ll int> v;
		//map<long int,long int> m;
		ll int x;
		//ll int s=0;
		//ll int flag=0;
		for(ll int i=0;i<n;i++)
		{
			cin>>x;
			//m[x]++;
			v.push_back(x);

		}
		sort(v.begin(),v.end());
		int i=0,sum=0;
		while(k--)
		{
			sum+=v[i++];
		}
		cout<<sum<<endl;

	}
}


