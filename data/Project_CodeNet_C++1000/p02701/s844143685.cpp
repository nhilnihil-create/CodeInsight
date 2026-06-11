#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	map<string,ll>m;
	string s;
	cin>>n;
	while (n--)
	{
		cin>>s;
		m[s]++;
	}
	cout<<m.size()<<"\n";
}