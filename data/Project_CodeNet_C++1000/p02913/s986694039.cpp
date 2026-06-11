//解説あり
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

void Zalgorithm(vector<int> &Z, string S) {
	int n = S.size();
	Z.push_back(n);
	int i = 1, j = 0;
	while(i < n) {
		while (i + j < n && S[j] == S[i+j]) j++;
		Z.push_back(j);

		if (j == 0) {
			i++;
			continue;
		}

		int k = 1;
		while (k < j && k + Z[k] < j) {
			Z.push_back(Z[k]);
			k++;
		}
		i += k;
		j -= k;
	}
    return;
}

int main(void) {
  string s;
  int n;
  cin >> n >> s;

  int ans = 0;
  rep(i, 0, n) {
      vector<int> Z;
      Zalgorithm(Z, s.substr(i, n-i));
      rep(j, 0, Z.size()) {
          ans = max(ans, min(Z[j], j));
      }
  }

    cout << ans << endl;

	return 0;
}
