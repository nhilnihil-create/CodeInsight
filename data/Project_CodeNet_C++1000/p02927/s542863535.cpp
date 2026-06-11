#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n) ;i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
 int M, D; cin >> M >> D;
int ans = 0;
for (int m = 1; m <= M; ++m) {
for (int d = 10; d <= D; ++d) {
int d_1 = d % 10, d_10 = d / 10;
if (d_1 >= 2 && d_10 >= 2 && d_1 * d_10 == m) {
++ans; }
} }
cout << ans << endl; }
