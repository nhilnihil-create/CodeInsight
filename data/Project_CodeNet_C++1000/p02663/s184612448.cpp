#include <iostream>
using namespace std;

int h1, m1, h2, m2, k, ans;

int main() {
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    ans = (h2-h1) * 60;
    ans += m2-m1;
    ans -= k;
    cout << ans << "\n";
}
