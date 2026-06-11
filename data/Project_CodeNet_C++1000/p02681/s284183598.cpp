#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void solve()
{
	string s, t;
	cin >> s >> t;
	
	if(s.length()>=1 && s.length()<=10 && t.length() == s.length()+1 && t.substr(0, s.length()) == s)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
