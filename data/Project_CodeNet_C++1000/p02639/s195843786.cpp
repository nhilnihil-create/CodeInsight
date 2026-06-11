#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a, b, c, d, e, ans;
    cin >> a >> b >> c >> d >> e;
    
    if (a == 0) ans = 1;
    if (b == 0) ans = 2;
    if (c == 0) ans = 3;
    if (d == 0) ans = 4;
    if (e == 0) ans = 5;
    
    cout << ans << endl;
}