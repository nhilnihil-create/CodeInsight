#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
	cin >> n;
	vector<float> ma(n);
	REP(i,n) cin >> ma[i];
	float t = 0;
	int f = n;
	float ans = 0;
	while(ma.size()!=1) {
		sort(ma.begin(),ma.end());
		reverse(ma.begin(),ma.end());
		t = ma[f-1] + ma[f-2];
		t/=2;
		ma.pop_back();
		ma.pop_back();
		ma.push_back(t);
		ans += t;
		f--;
 		//  cout << t << endl;

	}

  cout << t << endl;
}
