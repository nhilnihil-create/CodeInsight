#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int prime[300000];
int main() {
	prime[1] = 1;
	for(int i = 2; i * i <= 246912; i++) {
		if(prime[i] == 1) continue;
		for(int j = i * i; j <= 246912; j += i) {
			prime[j] = 1;
		}
	}
	int n;
	while(cin >> n,n) {
		int ans = 0;
		for(int i = n + 1; i <= n * 2; i++) {
			if(prime[i] == 0) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}