#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a, ans;
    cin >> a;
    
    if (a <= 10000) ans = 10000 - a;
    if (a <= 9000) ans = 9000 - a;
    if (a <= 8000) ans = 8000 - a;
    if (a <= 7000) ans = 7000 - a;
    if (a <= 6000) ans = 6000 - a;
    if (a <= 5000) ans = 5000 - a;
    if (a <= 4000) ans = 4000 - a;
    if (a <= 3000) ans = 3000 - a;
    if (a <= 2000) ans = 2000 - a;
    if (a <= 1000) ans = 1000 - a;
    
    cout << ans << endl;
}