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

int E(int a) {
	return (5 * a + 17) % 32;
}

int D(int a) {
	return (13 * (a - 17 + 32)) % 32;
}

void Cout(vector<int> A) {
	for (auto x : A) {
		char c = x + 'a';
		cout << c;
	}
	cout << endl;
}

int main() {
	int i, j, k;

	int N, M, K;
	int Q;

	int S;
	cin >> N >> K >> S;
	int other = S - 1;
	if (other == 0) {
		other = 100000;
	}
	rep(i, 0, K) {
		cout << S << " ";
	}
	rep(i, K, N) {
		cout << other << " ";
	}
	return 0;
}