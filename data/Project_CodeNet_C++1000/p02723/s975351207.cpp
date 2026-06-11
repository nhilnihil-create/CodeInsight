#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	string s;
	cin >> s;

	bool res = true;
	if(s.at(2) != s.at(3)) res = false;
	if(s.at(4) != s.at(5)) res = false;

	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
