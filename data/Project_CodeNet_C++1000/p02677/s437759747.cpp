#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    int A,B,H,M;
    cin >> A >> B >> H >> M;
    long double ans = 0;
    long double rad = M_PI * 2*(
        (long double) H/12.0 +(long double) M/(60.0)/12.0 - (long double)M/60
        );
    ans = (long double)(A*A + B*B) - (long double)(2*A*B*cos(rad));
    cout << fixed << setprecision(20) << sqrt(ans) << endl;
    return 0;
}