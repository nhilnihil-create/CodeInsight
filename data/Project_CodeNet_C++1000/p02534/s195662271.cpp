#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin    );
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	string s = "";
	while (n--)
		s += "ACL";
	cout << s << endl;
	return 0;
}