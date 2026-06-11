#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i>b;i--)
#define vint vector<int> 
#define vvint vector<vint>
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int INF = 1e9+7;
const int mod= 1e9 + 7;

vector<int> V;
string S;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, K, ans = 0;

	cin >> N >> K;
	cin >> S;
	char cur = S[0];
	V.push_back(S[0]);
	FOR(i, 1, S.length()) {
		if (cur == S[i])ans++;
		else {
			V.push_back(S[i]);
			cur = S[i];
		}
	}
		ans += min(2 * K, int(V.size()) - 1);

		cout << ans << endl;




	return 0;
}
