//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
#include "bits/stdc++.h"

#define rep(i,n) for(long long (i)=0;(i)<(long long)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define int long long

#define PI (3.14159265358979323)
#define MOD (1000000007LL)
#define INF (1LL<<60LL)
#define MAX_N (10000001)
#define MAX (1000000000000000000LL)
using namespace std;

signed main() {
	int n; cin >> n;
	vector<int> isprime(MAX_N, 1);
	isprime[0] = isprime[1] = 0;
	rep(i, MAX_N) {
		if (isprime[i]) {
			int k = i * 2;
			while (k < MAX_N) {
				isprime[k] = 0;
				k += i;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < MAX_N; i++) if(isprime[i]){
		int j = i;
		while (n % j == 0) {
			//cout << j << endl;
			ans++;
			n /= j;
			j *= i;
			//cout << n << endl;
		}
	}
	bool flag = true;
	if (n == 1)flag = false;
	for (int i = 2; i < MAX_N; i++) if (isprime[i]) {
		if (n % i == 0) {
			flag = false;
		}
	}
	if(flag)ans++;
	cout << ans << endl;
}