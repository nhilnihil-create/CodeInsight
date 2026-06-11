#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1 << 30;


int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> u(n+1),v(n+1);
    rep(i,n) u[i+1] = u[i] + (s[i] != 'R');
    drep(i,n) v[i] = v[i+1] + (s[i] != 'W');

    int res = INF;
    rep(i,n+1) chmin(res,max(u[i],v[i]));
    cout << res << endl;
    return 0;
}