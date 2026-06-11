#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll c(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

int main(void) {
	int H, W, c;
	cin >> H >> W;
	vector<string> s(H);
	vector<vector<int>> tate(H, vector<int>(W, 0)), yoko(H, vector<int>(W, 0));
	rep(i, 0, H)cin >> s[i];
	rep(y, 0, H) {
		rep(x, 0, W) {
			if (s[y][x] == '#')continue;
			if (x && yoko[y][x - 1]) {
				yoko[y][x] = yoko[y][x - 1];
			}
			else{
				c = 0;
				rep(i, x, W) {
					if (s[y][i] == '#')break;
					c++;
				}
				yoko[y][x] = c;
			}
		}
	}
	rep(y, 0, H) {
		rep(x, 0, W) {
			if (s[y][x] == '#')continue;
			if (y && tate[y - 1][x]) {
				tate[y][x] = tate[y - 1][x];
			}
			else {
				c = 0;
				rep(i, y, H) {
					if (s[i][x] == '#')break;
					c++;
				}
				tate[y][x] = c;
			}
		}
	}
	int M = 0;
	rep(y, 0, H) {
		rep(x, 0, W) {
			//printf("%2d ", tate[y][x] + yoko[y][x] - 1);
			M = max(M, tate[y][x] + yoko[y][x] - 1);
		}
		//puts("");
	}
	printf("%d\n", M);
	return 0;
}