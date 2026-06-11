#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double vol = a * a * b;
    double res, ang;
    if (vol <= x*2){
        res = 2 * (vol - x) / (a*a);
        ang = 90 - asin(a / sqrt((res*res + a*a))) * 180 / M_PI;
    } else{
        res = 2 * x / (a*b);
        ang = 90 - asin(res / sqrt((res*res + b*b))) * 180 / M_PI;
    }
    printf("%.12f", ang);
}