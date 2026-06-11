#include <bits/stdc++.h>
#define lli long long int
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(lli i=0, i##_len=(lli)(n); i<i##_len; i++)
#define repf(i, n) for(lli i=1, i##_len=(lli)(n+1); i<i##_len; i++)
#define per(i, n) for(lli i=((lli)(n))-1; i>=0; i--)
#define perf(i, n) for(lli i=((lli)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<lli>
#define vvi vector<vector<lli>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    lli a, b, c;
    cin >> a >> b >> c;
    c -= (a-b);
    cout << ((c < 0) ? 0 : c ) << endl;
}