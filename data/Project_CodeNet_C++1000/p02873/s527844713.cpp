#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int) 1e6;

int n, a[N], d[N], v[N];
char s[N];
vector <int> q;
vector <int> g[N];

int main() {

	scanf("%s", s);

	int n = strlen(s);
	
	for (int i = 0; i <= n; i++) {
		d[i] = 0;
		v[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (s[i] == '<') {
			d[i + 1]++;
			g[i].push_back(i + 1);
		} else if (s[i] == '>') {
			d[i]++;
			g[i + 1].push_back(i);
		}
	}

	n++;

	for (int i = 0; i < n; i++) {
		if (d[i] == 0) {
			v[i] = 0;
			q.push_back(i);
		}
	}

	for (int i = 0; i < q.size(); i++) {
		int now = q[i];
		for (int j = 0; j < g[now].size(); j++) {
			int cur = g[now][j];
			v[cur] = max(v[cur], v[now] + 1);
			if (--d[cur] == 0) q.push_back(cur);
		}
	}

	long long res = 0;

	for (int i = 0; i < n; i++) {
		res += v[i];
	}

	printf("%lld\n", res);

	return 0;

}