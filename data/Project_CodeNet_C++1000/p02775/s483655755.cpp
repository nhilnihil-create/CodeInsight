#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

string S;
cin >> S;
S = "0" + S;
int N = S.size();

int dp[N+5][2];

dp[0][0] = 0;
dp[0][1] = 1;

rep(i,N-1) {
    int D = S[i+1] - '0';
    dp[i+1][0] = min(dp[i][0] + D, dp[i][1] + 10-D);
    dp[i+1][1] = min(dp[i][0] + D+1, dp[i][1] + 9-D);
}
cout << dp[N-1][0] << endl;
return 0;
}