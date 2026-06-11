#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> r, g, b;
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
			case 'R':
				r.push_back(i);
				break;
			case 'G':
				g.push_back(i);
				break;
			case 'B':
				b.push_back(i);
				break;
		}
	}
	long long count = 0;
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < g.size(); j++) {
			int v = b.size();
			int s = min(r[i], g[j]);
			int l = max(r[i], g[j]);
			if (binary_search(b.begin(), b.end(), l + (l-s)))
				v--;
			if (binary_search(b.begin(), b.end(), s - (l-s)))
				v--;
			if ((l-s) % 2 == 0)
				if (binary_search(b.begin(), b.end(), s + (l-s)/2))
					v--;
			count += v;
		}
	}
	cout << count << endl;
	return 0;
}