#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;



int main()
{

	io;
	
	string s; cin >> s;
	auto it = s.end();
	it--;
	if (*it == 's') cout << s << "es";
	else cout << s << "s";
	
}

