#include <bits/stdc++.h>
using namespace std;

/* {{{ */
#define PI(N) (M_PI * (N) / 180) //?§???????????????¢??????????????????
#define CL(N) cout << (N) << endl
#define DCT(N) (cout << "debug " << (N) << endl)
#define REP(i, N) for (int i = 0; i < (N); i++)
/* }}} */

int main()
{
    double  a, b, c;
                
    cin >> a >> b >> c;
    
    printf("%f\n", a * b / 2 * sin(PI(c)));
    printf("%f\n", a + b + sqrt(a * a + b * b - 2 * a * b * cos(PI(c))));
    printf("%f\n", b * sin(PI(c)));
    
    return (0);
}