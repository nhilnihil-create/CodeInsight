#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	string s; cin >> s;
	vector<string> v;
	v.push_back(s);
	if(s[s.size()-1] == 's') v.push_back("es");
	else v.push_back("s");
	for(auto a : v) cout << a;

    return 0;
}
