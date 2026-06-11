#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main() {
	string t;
	cin >> t;
	int c = 0;
	vector<string>  vec = {"Sunny","Cloudy","Rainy"};
	REP(i,3) if (vec[i] == t ) c = (i+1)%3;
  cout << vec[c] << endl;
}
