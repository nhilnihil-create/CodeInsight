#include <bits/stdc++.h>

#define lli long long int
#define ii pair<int, int>
#define ll pair<lli, lli>
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define fi first
#define se second

using namespace std;

int main() {
	int n, t[55], ans = 0;
	char s[105];
	string ss;
	map<string, int> id;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", s, &t[i]);
		ss = s;
		id[ss] = i;
	}
	scanf("%s", s);
	ss = s;
	for (int i = id[ss] + 1; i < n; i++)
		ans += t[i];
	printf("%d\n", ans);
	return 0;
}