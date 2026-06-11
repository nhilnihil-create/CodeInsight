#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, a, b;
	scanf("%d%d%d", &k, &a, &b);
	
	int least = k * ((a + k - 1) / k);
	
	if (least <= b) printf("OK\n");
	else printf("NG\n");
}
