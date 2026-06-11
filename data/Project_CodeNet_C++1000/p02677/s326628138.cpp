#include <bits/stdc++.h>

using namespace std;
 
//#define int long long
using ll = long long;
#define all(v) (v).begin(), (v).end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define reps(i,n) for(ll i=0;i<=n;i++)
#define PI 3.14159265358979323846264338327950L

ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
 
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ios_base::sync_with_stdio(false);
    long double a,b,h,m;
    cin >> a >> b >> h >> m;
    long double rad = 2*PI*((m/60.0)-(h/12.0+m/720.0));
    cout << fixed << setprecision(10) << sqrtl(a*a+b*b-2*a*b*cosl(rad)) << endl;
    return 0;
}
