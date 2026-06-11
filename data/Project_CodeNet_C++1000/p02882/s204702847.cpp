#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
const double PI = 3.1415926535;

int main() {
    double a,b,x;
    cin >> a >> b >> x;
    if(2*x>a*a*b)cout << fixed << setprecision(10) << (long double)(atan(2*(a*a*b-x)/(a*a*a))*180/PI) << endl; 
    else cout << fixed << setprecision(10) << (long double)(atan(a*b*b/(2*x))*180/PI) << endl; 
}