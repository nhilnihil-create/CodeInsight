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
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define INF 1 << 30
#define MAX 1000000000
#define SIZE 1000000000
int main() {
	int n, a, b, c, d, f, t;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	char str[200000];
	scanf("%s", str);
	a--, b--, c--, d--;
	if (a < b) {
		swap(a, b);
		swap(c, d);
	}//a > bにする
	//printf("%d-%d %d-%d\n", a, c, b, d);
	if (c > d) {
		f = 1;
		rep(i, b, c) {
			if (str[i] == '#' && str[i] == str[i + 1]) {
				f = 0;
				break;
			}
		}
		puts(f ? "Yes" : "No");
	}
	else {// c < d
		f = 0;
		rep(i, a - 1, c) {
			if (str[i] == '.' && str[i + 1] == '.'&& str[i + 2] == '.') {
				f++;
			}
		}
		rep(i, b, d) {
			if (str[i] == '#' && str[i] == str[i + 1]) {
				f = 0;
				break;
			}
		}
		puts(f ? "Yes" : "No");
	}
	return 0;
}