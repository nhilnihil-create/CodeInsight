#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,  N = 1e7+5, ans = 0, f[N];
	memset(f,0,sizeof(f));
	cin >> n;
	for(long long i = 1; i < N; i++){
		for(long long j = i; j < N; j+=i){
			f[j]++;
		}
	}
	for(long long i = 1; i <= n; i++){
		ans += f[i]*i;
	}
	cout << ans << '\n';
}