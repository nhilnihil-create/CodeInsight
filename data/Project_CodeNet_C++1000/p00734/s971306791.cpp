#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>
#include <algorithm>
#include <string>
#include <climits>

#define REP(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define REG(i, a, b) for (int (i) = ((int)(a)); (i) < ((int)(b)); i++)
#define ALL(V) (V).begin(), (V).end()
#define PRINT(STR) cout << (STR) << endl

typedef long long ll;
using namespace std;
const int INF = 999999;

int main() {
	cin.tie(0); //?????±?????????????????????
	ios::sync_with_stdio(false); //printf??¨??±??????????????????
	int n, m;
	int Taros[101];
	int Hanakos[101];
	while (cin >> n >> m, n + m != 0) {
		fill(Taros, Taros + 101, 0);
		fill(Hanakos, Hanakos + 101, 0);
		int sum1 = 0, sum2 = 0;
		REP(i, n) {
			cin >> Taros[i];
			sum1 += Taros[i];
		}
		REP(i, m) {
			cin >> Hanakos[i];
			sum2 += Hanakos[i];
		}
		int sum_min = INF, a, b;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (sum1 - Taros[i] + Hanakos[j] ==
						sum2 - Hanakos[j] + Taros[i]) {
					if (sum_min > Taros[i] + Hanakos[j]) {
						a = Taros[i];
						b = Hanakos[j];
						sum_min = a + b;
					}
				}
			}
		}
		if (sum_min == INF) {
			cout << -1 << endl;
		} else {
			cout << a << " " << b << endl;
		}
	}

	return 0;
}