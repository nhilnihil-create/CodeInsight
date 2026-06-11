#include <bits/stdc++.h>
using namespace std;

// #define TEST_CASES
using ll = long long;
#define ff first
#define ss second
const int N = 1e5 + 10;

void solve()
{
	int a, b, c;
	cin>>a>>b>>c;
	int r = a - b;
	if (r >= c) cout<<0<<endl;
	else cout<<c - r<<endl; 
}

int main()
{
	int t = 1;
#ifdef TEST_CASES
	cin>>t;
#endif
	while(t--)
	{
		solve();
	}
}

