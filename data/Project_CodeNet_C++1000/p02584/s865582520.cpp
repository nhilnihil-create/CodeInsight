#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve()
{
	ll n,k,d,m;
	cin>>n>>k>>d;
	n=abs(n);
	m=min(k,abs(n)/d);
	k=k-m;
	n=n-m*d;
	if(k%2==0)
	{
		cout<<n<<endl;
		return;
	}
	else
	{
		cout<<d-n<<endl;return;
	}



}





int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;

	while (t--)
	{
		solve();
	}


	return 0;
}
