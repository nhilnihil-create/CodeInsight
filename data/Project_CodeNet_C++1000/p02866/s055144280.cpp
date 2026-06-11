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
#define P pair<int,int>
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

int main() {
	lint MOD = 998244353;
	lint N;
	cin >> N;
	vector<lint>D(N);
	rep(i, N) {
		cin >> D[i];
	}
	vector<lint>A(N);
	rep(i, N) {
		A[D[i]]++;
	}
	vector<lint>AA;
	reverse(A);
	bool flag = false;
	rep(i, N) {
		if (A[i] == 0 &&flag==false) {

		}
		else {
			flag = true;
			AA.push_back(A[i]);
		}
	}
	reverse(AA);
	if (D[0] == 0 && AA[0] == 1) {

		lint ans = 1;
		rep(i, AA.size() - 1) {
			ans *= power(AA[i], AA[i + 1], MOD);
			ans %= MOD;
		}
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
}