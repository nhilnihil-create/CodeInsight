#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c, k; cin >> a >> b >> c >> k;
    int ans = min(a, k) - max(0, k - b - a);
    cout << ans << endl;
}
