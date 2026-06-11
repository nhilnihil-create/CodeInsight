#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	string s;
	cin >> s;

	map<char, int> mp;
	rep(i, s.size()){
		mp[s.at(i)]++;
	}

	if(mp.size() == 2 && mp[s.at(0)] == 2)
		cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
