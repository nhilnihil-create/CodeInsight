#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll k,s,i;
cin>>k;
s=7;
for(i=1;i<=k;i++)
{
	if(s%k==0)
	{
		cout<<i<<endl;
		return;
	}
	s=(s*10+7)%k;
}
cout<<-1<<endl;return; 


}






int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t=1;
	//cin >> t;

	while (t--)
	{
		solve();
	}


	return 0;
}
