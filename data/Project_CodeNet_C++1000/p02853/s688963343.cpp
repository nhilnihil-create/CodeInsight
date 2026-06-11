#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;
    int answer = 0;

    if (X <= 3) answer += (4 - X) * 1e5;
    if (Y <= 3) answer += (4 - Y) * 1e5;
    if (X == 1 && Y == 1) answer += 4e5;

    cout << answer << '\n';
}
