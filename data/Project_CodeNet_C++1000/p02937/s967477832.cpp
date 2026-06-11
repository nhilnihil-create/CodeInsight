#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[27];

int main() {
	string s;
	cin >> s;
	string str;
	cin >> str;
	int n = s.size();
	for(int i = 0; i < n; ++i)
		adj[s[i] - 'a'].push_back(i);
	long long answer = 1, last = -1;
	bool ok = false;
	n = str.size();
	for(int i = 0; i < n; ++i) {
		vector<int> :: iterator it = upper_bound(adj[str[i] - 'a'].begin(), adj[str[i] - 'a'].end(), last);
		if(it == adj[str[i] - 'a'].end()) {
			++answer;
			if(ok)
				return cout << -1, 0;
			ok = true;
			last = -1;
			--i;
			continue;
		}
		last = *it;
		ok = false;
	}
	--answer;
	n = s.size();
	cout << answer * n + last + 1;
}
