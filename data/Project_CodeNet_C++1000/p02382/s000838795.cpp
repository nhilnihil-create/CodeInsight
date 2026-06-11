#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

int main()
{
    using namespace std;
    
    int n, i, t, x[1000], y[1000];
    double ans1, ans2, ans3, ans4;
    
    cin >> n;
    
    for (i = 0; i < n; ++i) cin >> x[i];
    for (i = 0; i < n; ++i) cin >> y[i];
    
    ans1 = ans2 = ans3 = ans4 = 0;
    
    for (i = 0; i < n; ++i) { 
        t = abs(x[i] - y[i]);
        ans1 += t;
        ans2 += t * t;
        ans3 += t * t * t;
        if (ans4 < t) ans4 = t;
    }

    cout << fixed << ans1 << endl 
    << sqrt(ans2) << endl
    << cbrt(ans3) << endl
    << ans4 << endl;

    return 0;
}