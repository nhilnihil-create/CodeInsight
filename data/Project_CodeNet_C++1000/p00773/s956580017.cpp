#include<iostream>
#include<algorithm>
using namespace std;
#define FOR(i, a, n) for(int i=a; i<n; i++)
#define RFOR(i, a, n) for(int i=n-1; i>=a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)

int main()
{
	int x, y, s;
	while (cin >> x >> y >> s, x||y||s) {
		int max_v = 0;
		FOR(i, 1, s) {
			FOR(j, 1, s) {
				int val = i*(100 + x) / 100 + j*(100 + x) / 100;
				if (val == s) {
					max_v = max(max_v, i * (100 + y) / 100 + j * (100 + y) / 100);
				}
				if (val > s) break;
			}
		}

		cout << max_v << endl;
	}
	return 0;
}