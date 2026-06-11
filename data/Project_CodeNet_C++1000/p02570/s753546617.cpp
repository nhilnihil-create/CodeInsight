#include <bits/stdc++.h>
using namespace std;

string check(int d, int t, int s)
{
	int d1;
	d1= t*s;
	if(d1>=d) return "Yes";

	return "No";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	int d,t,s;
	cin>>d>>t>>s;
	cout<<check(d,t,s);
	return 0;
}

