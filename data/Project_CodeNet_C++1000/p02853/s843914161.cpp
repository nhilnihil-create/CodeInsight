#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <cmath>
#include <limits>
#include <bitset> 
#include <iterator> 
#include <map>
#include <queue>
#include <set>
#include<deque>
#define rep(i,n) for(ll i=0;i<(n); ++i)
#define per(i,n) for(ll i=n-1;i>=0; --i)
#define all(x) (x).begin(),(x).end()
#define _GLIBCXX_DEBUG
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
typedef long long ll;
const ll MOD = 1000000007;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll x, y,prize=0;
	cin >> x >> y;
	if (x == 1 && y == 1)prize += 4;
	if (x == 1)prize += 3;
	if (y == 1)prize += 3;
	if (x == 2)prize += 2;
	if (y == 2)prize += 2;
	if (x == 3)prize += 1;
	if (y == 3)prize += 1;
	cout << setprecision(10) << prize * pow(10,5) << endl;
}