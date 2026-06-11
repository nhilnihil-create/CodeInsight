#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	set<string>coll;
	while(n--)
	{
		string s;
		cin>>s;
		coll.insert(s);
	}
	int ans=coll.size();
	cout<<ans;
	return 0;
	
}