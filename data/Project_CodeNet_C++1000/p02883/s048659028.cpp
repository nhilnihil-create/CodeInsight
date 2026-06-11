#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = (1LL << 31) - 1;
const ll mod = 1e9 + 7;


ll N,K;
ll A[200001];
ll C[200001];
ll F[200001];


bool isOK(ll num) {
	ll cnt = K;


	FOR(i, 0, N) {
		ll x = A[i] - num / F[i];
		cnt -= max(x, 0LL);
	}


	if (cnt >= 0)return true;
	else return false;
}


ll binary_search() {

	ll left = -1, right = 1e12;
	while (right - left > 1) {
		ll mid = left + (right - left) / 2;

		if (isOK(mid))right = mid;
		else left = mid;
	}
	return right;
}


int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> N >> K;
	FOR(i, 0, N) {
		cin >> A[i];
	}
	sort(A, A + N);
	FOR(i, 0, N) {
		cin >> F[i];
	}
	sort(F, F + N);
	reverse(F, F + N);

	ll NUM = binary_search();

	cout << NUM << endl;
	


	return 0;
}