#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int mxN = 105;
vector<int> adj[mxN];

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i)
		adj[(int)s[i]].push_back(i);
	long long tot = 0;
	vector<int> :: iterator it;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(s[i] != s[j]) {
				char c;
				for(char x : {'R', 'G', 'B'}) {
					if(x == s[i] || x == s[j])
						continue;
					c = x;
				}
				it = upper_bound(adj[(int)c].begin(), adj[(int)c].end(), j);
				if(it != adj[(int)c].end()) {
					tot += ((int)adj[(int)c].size() - (it - adj[(int)c].begin())) - 
					binary_search(adj[(int)c].begin(), adj[(int)c].end(), j + (j - i));
				}
			}	
		}
	}
	cout << tot;
}
