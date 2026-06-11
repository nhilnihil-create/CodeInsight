#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
using namespace std;


#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>


int main() {
	long double a, b, c;
	cin >> a >> b >> c;
	long double eps = 1.0E-15;
	if (sqrt(a) + sqrt(b) + eps < sqrt(c))  cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;

}