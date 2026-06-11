#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long double EPS = 0.0000000001;

long double f(long double a, long double b,long double t){
    if(t > M_PI / 2.0 - EPS)return 0.0;
    if(a * tan(t) <= b)return a * a * b - a * a * a * tan(t) / 2.0;
    else return b * b / tan(t) * a / 2.0;
}

//ミョ(-ω- ?)
int main() {
    long double a,b,x;
    cin >> a >> b >> x;
    long double ok = M_PI/2.0;
    long double ng = 0.0;
    rep(_,100000){
        long double mid = (ok + ng)/2.0;
        if(f(a,b,mid) < x)ok = mid;
        else ng = mid;
    }
    cout << fixed << setprecision(10) << ok / M_PI * 180 << "\n";
    return 0;
}