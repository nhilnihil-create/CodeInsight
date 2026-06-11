#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int MOD = 1000000007;

int n, i, j, res, ind, act, last;
VI beg, fin;
bool inv;
char t[200005];

bool get(int ind, bool inv) {
	if (inv) return t[ind] == 'W';
	return t[ind] == 'B';
}

int main() {
scanf("%d", &n);
scanf("%s", t);
if (t[0] == 'W' || t[2 * n - 1] == 'W') {
	printf("0\n");
	return 0;
}
beg.clear();
fin.clear();
beg.pb(0);
last = 0;
for (i=1;i<2*n;i++) {
	if (t[i] != t[i - 1]) {
		if (last == 0) beg.pb(i); else fin.pb(i);
	} else {
		if (last == 0) fin.pb(i); else beg.pb(i);
		last = 1 - last;
	}
}

if (beg.size() != fin.size()) {
	printf("0\n");
	return 0;
}
sort(beg.begin(), beg.end());
sort(fin.begin(), fin.end());
res = 1;
ind = n; 
for (i = n - 1;i >= 0;i--) {
	while (ind - 1 >= 0 && fin[ind - 1] > beg[i]) ind--;
	act = i - ind + 1;
	res = (res * 1LL * act) % MOD;
}
for (i=2;i<=n;i++) res = (res * 1LL * i) % MOD;
printf("%d\n", res);
return 0;
}