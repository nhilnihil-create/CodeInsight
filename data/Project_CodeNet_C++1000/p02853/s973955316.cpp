#include <iostream>
using namespace std;
int main() {
    int X, Y; cin >> X >> Y;
    int ans = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (i == X) {
            ans += (4 - i) * 100000;
        }
    }
    for (int i = 1; i <= 3; i++)
    {
        if (i == Y) {
            ans += (4 - i) * 100000;
        }
    }
    if (X == 1 && Y == 1) ans += 400000;
    printf("%d\n", ans);
}