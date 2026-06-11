#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define yn(x, ok, ng) cout << ((x)?(ok):(ng)) << endl
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
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

ii3(n, k, c);
string s; cin >> s;

vi l(n), r(n); //左or右から貪欲で働くときに選ぶことになる'o'の情報を持っておく
int cur = 0;
rep(i,n) {
    if(cur == 0) {
        if(s[i] == 'o') {
            l[i] = 1;
            cur = c;
        }
    }
    else cur--;
}

cur = 0;
drep(i,n) {
    if(cur == 0) {
        if(s[i] == 'o') {
            r[i] = 1;
            cur = c;
        }
    }
    else cur--;
}

vi sl(n+1), sr(n+1);
rep(i,n) sl[i+1] = sl[i] + l[i];
drep(i,n) sr[i] = sr[i+1] + r[i];

rrep(i, n) {
    if(s[i-1] == 'o') {
        if(sl[i-1] + sr[i] < k) cout << i << endl;
    }
}
cout << endl;
return 0;
}