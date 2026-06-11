#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>


#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using tlll = tuple<lli, lli, lli>;
using vll = vector<lli>;

lli mod197 = 1000000007LL;
lli INF = 10000000000000;

// ax + by = gcd(a,b) 最大公約数
template< typename T >
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

lli C[300005] = {};
lli D[300005] = {};
lli ruiseki1[300005] = {};
lli ruiseki2[300005] = {};
lli ans[300005] = {};


int main(void) {

	lli N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		lli A;
		cin >> A;

		//Cがその数がいくつあるかの配列になる
		C[--A]++;
	}

	for (int i = 0; i < N; i++) {
		//Dが個数がkある数がいくつあるか？の配列
		D[C[i]]++;
	}

	for (int i = 0; i < N; i++) {
		ruiseki1[i + 1] = i * D[i] + ruiseki1[i];
	}

	for (int i = 1; i <= N; i++) {
		ruiseki2[i + 1] = D[i] + ruiseki2[i];
	}

	//K個(長さK)食べるとして、X回食べれる最大の長さは？
	//Xよりも個数が小さい数は、すべて使える。
	//X以上の個数が多い数は全ては使えない。最大使えてX。
	//鳩ノ巣理論的に同じところで選ばなければいけないから
	for (lli X = 1; X <= N; X++) {
		lli sum = 0;
		//ココが重いから累積和を使って高速化
		/*
		for (int i = 1; i < X; i++) {
			sum += i * D[i];
		}
		for (int i = X; i <= N; i++) {
			sum += X * D[i];
		}
		*/
		sum += ruiseki1[X];
		sum += (ruiseki2[N + 1] - ruiseki2[X]) * X;
		sum /= X;
		//COUT(sum);
		//長さにマッピングしなおす
		ans[sum] = std::max(ans[sum], X);
	}

	//長さiである個数食べれたならi-1でもその個数食べれるはず
	for (int i = N; i > 0; i--) {
		ans[i - 1] = std::max(ans[i - 1], ans[i]);
	}

	for (int i = 1; i <= N; i++) {
		COUT(ans[i]);
	}

	return 0;
}