#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;

ll dp[2020][2020];

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);


int N;
cin >> N;
vl A(N);
rep(i,N) cin >> A[i];

vector<pll> P(N);
rep(i,N) {
    P[i] = {A[i],i};
}
sort(P.rbegin(), P.rend());


rep(i,N) {
    for(int x = 0; x <= i; x++) {
        chmax(dp[x+1][i-x], dp[x][i-x] + P[i].first * abs(P[i].second - x));
        chmax(dp[x][i-x+1], dp[x][i-x] + P[i].first * abs(P[i].second - N + 1 + i - x));
    }
}
ll ans = 0;
for(int x = 0; x <= N; x++) {
    chmax(ans, dp[x][N-x]);
}
cout << ans << endl;
return 0;
}
