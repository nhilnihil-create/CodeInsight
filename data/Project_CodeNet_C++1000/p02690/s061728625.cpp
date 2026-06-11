#include <bits/stdc++.h>

using namespace std;

int main() {
	int x;
	scanf("%d", &x);
	
	for (int i = 1; ; i++) {
		long long tar = (long long)pow(i, 5) - 1LL * x;
		
		long long root = (long long)pow(abs(tar), 0.2);
		if (tar < 0) root *= -1;
		
		if (root * root * root * root * root == tar) return 0 * printf("%d %lld\n", i, root);
	}
}
