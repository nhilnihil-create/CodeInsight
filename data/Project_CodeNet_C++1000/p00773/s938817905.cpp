#define _CRT_SECURE_NO_WARNINGS // #pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
using namespace std; 

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define len(x) ((int)(x).size())
#define tmax(a,b,c) max((a),max((b),(c)))
#define tmin(a,b,c) min((a),min((b),(c)))
#define debug(x) cerr << #x << " is " << x << endl;

typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<vector<int> > VVi;
typedef long long ll;
const int inf = 2e9;
const ll ll_inf = 1e17;
const int mod = 1e9 + 7;
const long double eps = 1e-10;

int d[10101];

inline int calc(int i, int x)
{
	return i * (100 + x) / 100;
}

int main()
{
	while(1) {
		int x, y, s;
		cin >> x >> y >> s;
		if (!x && !y && !s) break;
		int l = 0, r = s;
		int a, b;
		int ans = 0;
		rep(i,1,s+1) rep(j,1,s+1) {
			if (calc(i, x) + calc(j, x) == s) {
				ans = max(ans, calc(i, y) + calc(j, y));
			}
		}
		cout << ans << endl;
	}

	return 0;
}