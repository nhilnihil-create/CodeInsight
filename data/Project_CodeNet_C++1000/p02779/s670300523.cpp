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
set<int> s;
	int n;
	int flag=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(s.find(x)==s.end())
		s.insert(x);
		else
		{
			flag=1;
		}
	}
	if(flag)
	cout<<"NO";
	else
	cout<<"YES";
}


