#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (int i = (int)(beg); i < (int)(end); i++)
#define FOR_LE(i, beg, end) for (int i = (int)(beg); i <= (int)(end); i++)
#define FOR_DW(i, beg, end) for (int i = (int)(beg); (int)(end) <= i; i--)
#define REP(n)              for (int repeat_index = 0; repeat_index < (int)n; repeat_index++)


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);

	int k, q; cin >> k >> q;

	vector<int64_t> ds(k); for (auto& d : ds) cin >> d;

	REP(q) {
		int64_t n, x, m; cin >> n >> x >> m;
		x %= m;
		n--;
		vector<int64_t> cds(k);
		int64_t cd = 0;
		FOR_LT(i, 0, k) {
			int64_t c = ds[i] % m;
			if (c == 0) c += m;
			cd += c;
			cds[i] = cd;
		}

		int64_t ndk = n / k;
		int64_t nrk = (n % k);

		int64_t fv = x + ndk * cds[k - 1];
		if (nrk != 0) {
			fv += cds[nrk - 1];
		}
		cout << (n  - fv / m) << endl;
	}

	return 0;
}