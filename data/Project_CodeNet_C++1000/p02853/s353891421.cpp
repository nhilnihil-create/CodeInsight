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
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e15;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

signed main() {
	int X, Y;
	cin >> X >> Y;
	cout << max((4 - X), 0ll) * 100000 + max((4 - Y), 0ll) * 100000 + (X == 1 && Y == 1) * 400000;
}