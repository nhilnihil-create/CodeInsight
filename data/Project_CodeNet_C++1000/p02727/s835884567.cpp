#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 998244353;// 1000000007;
const long long INF = 1e18;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned long long ULL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	LL X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	VLL P(A + 1,0), Q(B + 1,0), R(C + 1,0);
	for (LL a = 1; a <= A; a++)cin >> P[a];
	for (LL a = 1; a <= B; a++)cin >> Q[a];
	for (LL a = 1; a <= C; a++)cin >> R[a];
	sort(P.begin(), P.end(), [](LL a, LL b) {
		if (a == 0)return true;
		if (b == 0)return false;
		return a > b;
	});
	sort(Q.begin(), Q.end(), [](LL a, LL b) {
		if (a == 0)return true;
		if (b == 0)return false;
		return a > b;
	});
	sort(R.begin(), R.end(), [](LL a, LL b) {
		if (a == 0)return true;
		if (b == 0)return false;
		return a > b;
	});
	VLL PP(A + 1, 0), QQ(B + 1, 0), RR(C + 1, 0);
	for (LL a = 1; a <= A; a++)PP[a] = PP[a - 1] + P[a];
	for (LL a = 1; a <= B; a++)QQ[a] = QQ[a - 1] + Q[a];
	for (LL a = 1; a <= C; a++)RR[a] = RR[a - 1] + R[a];
	LL ans = 0;
	for (LL x = 0; x <= X; x++) {
		LL yb = max(X + Y - x - C, (LL)0);
		LL yu = min(X + Y - x, Y);
		if (yb > yu)continue;
		LL temp =0;
		if (yb == yu)temp = QQ[yb] + RR[X + Y - x - yb];
		else if (yu == yb + 1) {
			temp = max(QQ[yb] + RR[X + Y - x - yb], QQ[yu] + RR[X + Y - x - yu]);
		}
		else {
			LL s = yb, e = yu;
			while (e - s > 1) {
				LL m = (e + s) / 2;
				if (Q[m] - R[X + Y - x - m + 1] >= 0)s = m;
				else e = m;
			}
			temp = max(QQ[yb] + RR[X + Y - x - yb], QQ[yu] + RR[X + Y - x - yu]);
			temp = max(temp, QQ[s] + RR[X + Y - x - s]);
		}
		temp += PP[x];
		ans = max(ans, temp);
	}
	cout << ans << "\n";
	return 0;
}