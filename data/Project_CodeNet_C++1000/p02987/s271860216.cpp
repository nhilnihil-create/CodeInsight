#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	vector<int> al(26, 0);
	for (int i = 0; i < s.size(); i++)
	{
		al[s[i] - 'A']++;
	}
	if(count(al.begin(), al.end(), 2) == 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
