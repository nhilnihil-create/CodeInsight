#include<bits/stdc++.h>
const int M=300000;//M=1e6+100;
typedef long long int ll;
using namespace std;

ll n,x;
set<ll> s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s.insert(x);
	}
	if(s.size()==n)
	{
		cout<<"YES";
	} else cout<<"NO";
}