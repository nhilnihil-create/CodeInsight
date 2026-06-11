#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

const double PI = acos(-1);

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double ans;
    double c;
    if(x >= a * a * b / 2) {
        c = (a * a * a) / (2 * a * a * b - 2 * x); 
    } else {
        c = (2 * x) / (a * b * b);
    }
    ans = 90 - atan(c) * 180 / PI; 
    printf("%.10f\n", ans);

    return 0;
}