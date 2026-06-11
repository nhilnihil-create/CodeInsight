#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int x, y; cin >> x >> y;
    string ans;
    int diff = y - 2 * x;
    if (diff >= 0 && diff % 2 == 0 && diff / 2 <= x) ans = "Yes";
    else ans = "No";
    cout << ans << endl;
}
