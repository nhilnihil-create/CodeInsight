#include <iostream>
using namespace std;

int main ()
{
    char a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int ans = 0;
    if (a1 == a2)
        ans++;
    if (b1 == b2)
        ans++;
    if (c1 == c2)
        ans++;
    cout << ans;
}
