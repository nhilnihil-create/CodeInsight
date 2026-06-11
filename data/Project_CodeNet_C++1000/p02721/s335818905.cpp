#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int cnt[200005];
char s[200005];

int main() {
	int n, k, c;
	scanf("%d%d%d", &n, &k, &c);
	
	scanf("%s", s);
	
	vector <int> left;
	int cur = -INF;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') continue;
		if (i - cur <= c) continue;
		left.push_back(i);
		cur = i;
	}
	
	vector <int> right;
	cur = INF;
	
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'x') continue;
		if (cur - i <= c) continue;
		right.push_back(i);
		cur = i;
	}
	
	if (left.size() != k) return 0;
	
	for (int i = 0; i < left.size(); i++) cnt[left[i]]++;
	for (int i = 0; i < right.size(); i++) cnt[right[i]]++;
	
	for (int i = 0; i < n; i++) {
		if (cnt[i] == 2) printf("%d\n", i + 1);
	}
}
