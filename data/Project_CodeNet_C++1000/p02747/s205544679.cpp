#include <bits/stdc++.h>
#define R register
#define mp make_pair
#define ll long long
#define pii pair<int, int>
using namespace std;

char s[1000];

template <class T>
inline void read(T &x) {
	x = 0;
	char ch = getchar(), w = 0;
	while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	x = w ? -x : x;
	return;
}

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if (n & 1) return printf("No\n"), 0;
	for (R int i = 1; i <= n; i += 2)
		if (s[i] != 'h' || s[i + 1] != 'i') return printf("No\n"), 0;
	printf("Yes\n");
	return 0;
}