#include <bits/stdc++.h>
using namespace std;

string s, t;
int letterT[26];
vector<int> c[26];
int n = 0; //終わったsの数
int idx = -1; //今のsの中でのidx
long long ans = 0;

int main() {
	cin >> s >> t;
	for (int i = 0; i < (int) s.size(); i++)
		c[s[i] - 'a'].push_back(i);
	for (int i = 0; i < (int) t.size(); i++) {
		int inf = -1, sup = c[t[i] - 'a'].size();
		if (!sup) {
			cout << -1 << endl;
			return 0;
		}
		while (sup - inf > 1) {
			int mid = (inf + sup) / 2;
			if (c[t[i] - 'a'][mid] > idx)
				sup = mid;
			else
				inf = mid;
		}
		if (sup == (int)c[t[i] - 'a'].size()) {
			n++;
			sup = 0;
		}
		idx = c[t[i] - 'a'][sup];
	}
	cout << n * s.size() + idx + 1 << endl;
}

