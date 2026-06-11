#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    ans = max(a*c, a*d);
    ans = max(ans, b*c);
    ans = max(ans, b*d);
    cout << ans << endl;
    return 0;
}
