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

	
		ll int num,n;
		cin>>num>>n;
		ll int x;
		set<int> v;
		for(ll int i=0;i<n;i++)
		{
			cin>>x;
			v.insert(x);

		}
		int a,b;
		int s=0;
		while(1)
		{
			a=num-s;
			b=num+s;
			if(v.find(a)==v.end())
			{
				cout<<a<<endl;
				break;
			}
			
			
			
			if(v.find(b)==v.end())
			{
				cout<<b<<endl;
				break;
			}
			s++;
		}
		return 0;

	
}


