#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;

	string ans="No";
	if(s[0]==s[1] && s[2]==s[3] && s[0]!=s[2]) ans="Yes";
	if(s[0]==s[3] && s[1]==s[2] && s[0]!=s[1]) ans="Yes";
	if(s[0]==s[2] && s[1]==s[3] && s[0]!=s[1]) ans="Yes";
	cout << ans << endl;
}