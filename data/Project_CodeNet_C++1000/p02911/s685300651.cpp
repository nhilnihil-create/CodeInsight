#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> ma(a,0);
	int d = 0;
	REP(i,c){
		cin >> d;
		ma[d-1] += 1;
	}
	int ans = 0;
	REP(i,a) {
		if(c-b<ma[i]) cout << "Yes" << endl;
		else 	cout << "No" << endl;
	}
}
