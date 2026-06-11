#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int main() {
	string s;
	cin >> s;
	vector<ll> dp[2];
	dp[0].resize(s.size() + 1, 0);
	dp[1].resize(s.size() + 1, 0);
	dp[1][s.size()] = 1000000000000000000LL;
	for(int i =s.size()-1; i >= 0; --i){
		dp[0][i] = min(dp[0][i + 1] + s[i] - '0', dp[1][i + 1] + 1 + s[i] - '0');
		dp[1][i] = min(dp[0][i + 1] + 10 - (s[i] - '0'), dp[1][i + 1] + 9 - (s[i] - '0'));
	}
	PRI(min(dp[0][0], dp[1][0] + 1));
	return 0;
}


