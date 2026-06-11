#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
#define AAA (1000000007) 


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll powD(ll a, ll b) {
	ll ans = 1;
	a %= AAA;
	for (int i= 0; i <b; i++)
	{
		ans *= a;
		ans %= AAA;
	}
	return ans;
}



int main() {
	int i, j, k;

	int N, M, K;

	ll Num[61][2] = { {0} };

	cin >> N;

	rep(i, 0, N) {
		ll x;
		cin >> x;
		rep(j, 0, 61) {
			ll mask = (ll)1 << j;
			Num[j][(x & mask)==mask] ++;
		}

	}
	ll ans = 0;
	rep(i, 0, 61) {
		ll sum = Num[i][0] * Num[i][1];
		sum %= AAA;
		sum *= powD(2, i);
		sum %= AAA;
		ans = (sum + ans) % AAA;
	}
	cout << ans;
	return 0;
}