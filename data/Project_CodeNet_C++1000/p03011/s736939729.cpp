#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
	int a, b, c; cin >> a >> b >> c;
	int s = min(a + b, b + c);
	int u = min(s, a + c);
	cout << u << endl;
}