#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int H, W, A, B; cin >> H >> W >> A >> B;
	REP(r, H) {
		REP(c, W)
		{
			if (r < B && c < A)
			{
				cout << 0;
			}
			else if (r >= B && c >= A)
			{
				cout << 0;
			}
			else
			{
				cout << 1;
			}
		}
		cout << endl;
	}
}