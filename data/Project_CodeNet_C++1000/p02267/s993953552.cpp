#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <sstream>

#define rep(i, a) REP(i, 0, a)
#define REP(i, a, b) for(int i = a; i < b; ++i)
#define rrep(i, a) RREP(i, a, 0)
#define RREP(i, a, b) for(int i = a; i >= b; --i)
#define repll(i, a) REPLL(i, 0, a)
#define REPLL(i, a, b) for(ll i = a; i < b; ++i)
#define rrepll(i, a) RREPLL(i, a, 0)
#define RREPLL(i, a, b) for(ll i = a; i >= b; --i)

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> P;
typedef std::pair<int, P> PP;
const double PI = 3.14159265358979323846;
const double esp = 1e-9;
const int infi = (int)1e+9 + 10;
const ll infll = (ll)1e+18 + 10;

int n, q;
int s[10001], t[501];
int ans = 0;

int main(){
	std::cin >> n;
	rep(i, n)std::cin >> s[i];
	std::cin >> q;
	rep(i, q)std::cin >> t[i];

	std::sort(s, s + n);
	std::sort(t, t + q);

	rep(i, q){
		if (std::binary_search(s, s + n, t[i]))++ans;
	}

	std::cout << ans << std::endl;

	return 0;
}