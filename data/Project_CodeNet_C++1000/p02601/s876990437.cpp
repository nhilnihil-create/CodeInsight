#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 8;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int a, b, c, k; cin >> a >> b >> c >> k;
    int cnt = 0;
    while(a >= b) {
        b *= 2;
        ++cnt;
    }
    while(b >= c) {
        c *= 2;
        ++cnt;
    }
    cout << ((cnt > k) ? "No" : "Yes") << endl;
}
