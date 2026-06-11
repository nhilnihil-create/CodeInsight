#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll int x;
	string s;
	cin >> s;
	if(s[0]=='S' && s[1]=='U') cout << 7;
	else if(s[0]=='S' && s[1]=='A') cout << 1;
	else if(s[0]=='T' && s[1]=='U') cout << 5;
	else if(s[0]=='M' && s[1]=='O') cout << 6;
	else if(s[0]=='W' && s[1]=='E') cout << 4;
	else if(s[0]=='T' && s[1]=='H') cout << 3;
	else if(s[0]=='F' && s[1]=='R') cout << 2;
	
	return 0;
}