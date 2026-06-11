#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	int maxi = -1;
	map<string, int> mp;
	for(int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		++mp[s];
		maxi = max(maxi, mp[s]);
	}
	map<string, int> :: iterator it = mp.begin();
	vector<string> v;
	while(it != mp.end()) {
		if(it -> second == maxi)
			v.push_back(it-> first);
		++it;
	}
	for(string s : v)
		cout << s << '\n';
}
