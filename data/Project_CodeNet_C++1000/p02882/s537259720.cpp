#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    double a, b, x;
    cin >> a >> b >> x;

    double S = x / a;
    //printf("%.7lf\n", S);
    double ans;
    if (S >= (a * b / 2)) {
        double St = a * b - S;
        ans = atan2(2 * St, a * a);
        ans = (ans / acos(-1)) * 180.0;
    }
    else {
        ans = atan2(2 * S, b * b);
        ans = (ans / acos(-1)) * 180.0;
        ans = 90 - ans;
    }

    printf("%.7lf\n", ans);
    
    return 0;
}