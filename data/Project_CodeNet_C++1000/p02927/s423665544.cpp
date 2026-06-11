#include <iostream>
using namespace std;

int main() {
    int m, d;
    cin >> m >> d;
    int day = 22;
    int d10 = day/10, d1 = day%10;
    int ans = 0;
    while (day <= d) {
        if (d10 >= 2 && d1 >=2 && d10*d1 <= m) ans++;
        day++;
        d10 = day/10;
        d1 = day%10;
    }
    cout << ans << endl;
}