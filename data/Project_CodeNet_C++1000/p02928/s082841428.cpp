#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
#define mp make_pair
#define IP pair<int,int>
#define enld endl

lint power(lint x, lint n, lint m) {
	//(x^n)%mを返す
	lint res = 1;
	x %= m;
	while (n > 0) {
		if (n % 2 == 1) {
			res = res * x % m;
		}
		x = x * x % m;
		n /= 2;
	}
	return res;
}

lint invmod(lint n, lint m) {
	//nの逆元を返す
	lint ret = 0;
	ret = power(n, m - 2, m);
	return ret;
}


int main() {
	lint N, K;
	cin >> N >> K;
	lint MOD = pow(10, 9) + 7;
	vector<lint>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	lint S1 = 0;
	lint S2 = 0;
	rep(i, N) {
		rep(j, N) {
			if (A[i] > A[j]) {
				S1++;
				S1 %= MOD;
			}
		}
	}
	rep(i, N) {
		rep(j, N) {
			if (i < j) {
				if (A[i] > A[j]) {
					S2++;
					S2 %= MOD;
				}
			}
		}
	}
	lint ans = (K%MOD * S2%MOD)%MOD + K%MOD * (K - 1)%MOD*invmod(2,MOD)%MOD * S1%MOD;
	ans %= MOD;
	cout << ans << endl;
}