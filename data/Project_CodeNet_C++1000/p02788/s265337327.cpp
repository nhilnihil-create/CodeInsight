#include<iostream>
#include<algorithm>
#include<sstream>
#include<stack>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
#define req(i,n) for(int i = 1;i <= n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a)  (a).begin(),(a).end()
#define fix  fixed << setprecision(10)
const int MOD = 1000000007;
const ll INF = (1LL << 60);
string t, u; ll n, h, num = 0, k, q, ans = 0, sum = 0, a, d, r = 0;
bool f = true;
int main() {
    cin >> n >> d >> a;
    vector<pair<ll, ll>> x(n), b(n); vector<int> s(n + 1);
    rep(i, n) {
        cin >> q >> k;
        x[i] = make_pair(q, k);
    }sort(ALL(x));
    rep(i, n) {
        x[i].second -= s[i];
        while (r < n && x[r].first <= x[i].first + 2 * d)++r;
        if (x[i].second > 0) {
            num = (x[i].second + a - 1) / a;
            ans += num;
            s[i] += num * a;
            s[r] -= num * a;
        }
        s[i + 1] += s[i];
    }
    cout << ans << endl;
}