#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5, r = 0, s = 1, p = 2;
int n, k, a[N], vi[N];
string S;

int tonum(char x){
	if (x == 'r')
		return r;
	return x == 'p' ? p : s;
}

int towin(char x){
	if (x == 'r')
		return p;
	return x == 'p' ? s : r;
}

int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif

	scanf("%d %d", &n, &k);

	int val[3];

	scanf("%d %d %d", &val[0], &val[1], &val[2]);

	cin >> S;

	int ans = 0;

	for (int i = 0; i < n; i++){
		a[i] = towin(S[i]);
	}

	for (int i = n-1; i >= 0; i--){
		if (vi[i])
			continue;
		if (i - k < 0){
			ans += val[a[i]];
		} else {
			if (a[i] == a[i - k]){
				vi[i - k] = true;
			}
			ans += val[a[i]];
		}
	}

	printf("%d\n", ans);

	return 0;
}