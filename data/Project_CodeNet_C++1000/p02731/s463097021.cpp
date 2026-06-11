#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(void)
{
    int l; cin >> l;
    long double ans = (long double) (l * l * l) / 27.0;
    cout << fixed << setprecision(15) << ans << endl;
}