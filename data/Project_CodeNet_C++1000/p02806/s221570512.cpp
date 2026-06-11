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


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N; cin >> N;
vector<string> s(N);
vi t(N);
rep(i,N) cin >> s[i] >> t[i];
string X; cin >> X;

int p;
rep(i,N) {
    if(s[i] == X) p = i;
}
int ans = 0;
for(int i = p+1; i < N; ++i) {
    ans += t[i];
}
cout << ans << endl;
return 0;
}