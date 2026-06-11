#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int int64_t
#define ll long long

void solve()
{
int n,m;
cin>>n>>m;
if(n<m)
{
	for(int i=0;i<m;i++)
	cout<<n;
}else{
	for(int i=0;i<n;i++)
	cout<<m;
}
cout<<endl;


}

int32_t main()
{

	// int test;
	// cin >> test;
	// while (test--)
	{
		solve();
	}
	return 0;
}
