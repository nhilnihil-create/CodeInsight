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

	cin >> N;
	map<int, int> A;

	int first=-1;
	int second=1000000000;
	rep(i, 0, N) {
		int a;
		cin >> a;
		A[a] ++;
		first = Max(first, a);
		second = Min(second, a);
	}


	bool isClear = true;
	int left = first;
	int mid = second;
	auto X = A;
	X[left]--;
	X[mid]--;
	for (i = 1; i < N - 1; i++) {
		if (X[left ^ mid] < 1) {
			cout << "No";
			return 0;
		}
		int tmp = left;
		left = mid;
		mid = tmp ^ mid;
		X[mid]--;
	}
	if ((left ^ mid) != first) {
		cout << "No";
		return 0;
	}
	cout << "Yes";
	return 0;
}