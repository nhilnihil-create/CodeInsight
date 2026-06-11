#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << t[i];
	}
	return 0;
}