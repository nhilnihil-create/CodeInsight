#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int X, Y;
    int ans_reward = 0;
    int reward[] = {300000, 200000, 100000};
    cin >> X >> Y;
    if (X <= 3) {
        ans_reward += reward[X - 1];
    }
    if (Y <= 3) {
        ans_reward += reward[Y - 1];
    }
    if (X == 1 && Y == 1) {
        ans_reward += 400000;
    }
    cout << ans_reward << "\n";

    return 0;
}
