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
	vector<ll> ma(n);
	REP(i,n) cin >> ma[i];
	int c = 0;
	int M = 0;
	REP(i,n-1) {
		if (ma[i]>=ma[i+1]){

			c+=1;
			M = max(M,c);
		}
		else{
			c = 0;
		}
	}

  cout << M << endl;
}
