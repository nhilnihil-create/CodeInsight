#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int h1, m1;
	scanf("%d %d", &h1, &m1);
	int h2, m2;
	scanf("%d %d", &h2, &m2);
	int k;
	scanf("%d", &k);
	m1 += h1 * 60;
	m2 += h2 * 60;
	printf("%d\n", m2 - m1 - k);
	return 0;
}
