#define _USE_MATH_DEFINES
#pragma region include

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <bitset>

#include <queue>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <ctime>
////
//#include <random>//
#pragma endregion //#include
/////////

#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#pragma endregion //typedef
////定数
const int INF = (int)1e9 + 10;
const LL MOD = (LL)1e9 + 7;
const LL LINF = (LL)4e18 + 20;
const LD PI = acos(-1.0);
const double EPS = 1e-9; 
/////////
using namespace::std;
//////////////

void solve() {
	int N,M;
	cin >> N >> M;
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	vector<int> ans0(0);
	int now = 0;
	int prev = 0;

	vector<int> OK;
	for (int i = 0; i <= N; ++i) {
		if (str[i] == '0') {
			OK.push_back(i);
		}
	}
	while (now < N) {
		bool flag = false;
		int ter = now + M;
		if (ter >= N) {//ゴールしてる
			int res = N - now;
			ans0.push_back(res);
			now = N;
			break;
		}
		vector<int>::iterator pos;
		pos = lower_bound(OK.begin(), OK.end(), ter+1);
		if (pos==OK.begin() || pos == OK.begin()) {
			cout << -1 << endl;
			return;
		}

		--pos;
		int next = *pos;
		
		if (next == now) {
			cout << -1 << endl;
			return;
		}
		int temp = next;
		ans0.push_back(temp - now);
		now = temp;
	}

	int len = ans0.size();
	reverse(ans0.begin(), ans0.end());
	for (int i = 0; i < len; ++i) {
		if (i)cout << " ";
		cout << ans0[i];
	}
	cout << endl;
}

#pragma region main
signed main(void) {
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()
