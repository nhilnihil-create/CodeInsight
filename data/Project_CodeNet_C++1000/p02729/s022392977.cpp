#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a * (a - 1) / 2 + b * (b - 1) / 2);

}
