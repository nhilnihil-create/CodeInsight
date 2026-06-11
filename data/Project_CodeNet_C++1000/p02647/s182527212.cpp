#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

int a[200005];
int s[200005];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i=0 ; i<n ; i++) {
		scanf("%d", a+i);
	}
	if (k > 100) {
		for (int i=0 ; i<n ; i++) {
			printf("%d ", n);
		}
		printf("\n");
		return 0;
	}
	while (k--) {
		memset(s, 0, sizeof s);
		for (int i=0 ; i<n ; i++) {
			s[max(0, i-a[i])]++;
			s[min(200004, i+a[i]+1)]--;
		}
		int pos = 0;
		for (int i=0 ; i<n ; i++) {
			pos += s[i];
			a[i] = pos;
		}
	}
	for (int i=0 ; i<n ; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}