#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

int  main()
{
	string s;
	cin >> s;
	map<string, int> mp;
	mp["SUN"] = 7;
	mp["SAT"] = 1;
	mp["FRI"] = 2;
	mp["THU"] = 3;
	mp["WED"] = 4;
	mp["TUE"] = 5;
	mp["MON"] = 6;
	cout << mp[s] << endl;
	return (0);
}