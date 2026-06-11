#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	scanf("%d", &n);
	int t = ceil(n/1000.0);
	printf("%d", 1000*t - n); 
	return 0;
}