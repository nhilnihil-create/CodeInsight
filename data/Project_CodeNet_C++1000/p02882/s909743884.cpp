#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair



int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double theta;
    if (2 * x > a * a * b) theta = atan(2*b/a - 2*x/a/a/a);
    else theta = atan(a*b*b/2/x);
    theta = theta * 180 / M_PI;
    printf("%.7f\n", theta);
    return 0;
}