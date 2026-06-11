#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

#define rep(i, a) REP(i, 0, a)
#define REP(i, a, b) for(int i = a; i < b; ++i)

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> P;
typedef std::pair<P, int> PP;
const double PI = 3.14159265358979323846;
const double esp = 1e-9;
const int infi = (int)1e+9 + 10;
const ll infll = (ll)1e+17 + 10;

int main(){
	int n;
	while (std::cin >> n, n){
		double s[1001];
		double m, a = 0;
		rep(i, n)std::cin >> s[i];
		m = std::accumulate(s, s + n, 0.0) / n;
		rep(i, n)a += (s[i] - m) * (s[i] - m);
		a /= n;
		a = sqrt(a);
		printf("%.10lf\n", a);
	}
	return 0;
}