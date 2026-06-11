#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include <ctime>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define dup(x,y) (((x)+(y)-1)/(y))
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int N, K;
	cin >> N >> K;
	vector<int>A(N);
	rep(i, N)cin >> A[i];
	int left = 0;
	int right = 1e9;
	while (right - left > 1) {
		int mid = (left + right) / 2;
		int cnt = 0;
		rep(i, N) {
			cnt += dup(A[i], mid) - 1;
		}
		if (cnt <= K)right = mid;
		else left = mid;
	}
	cout << right;
}