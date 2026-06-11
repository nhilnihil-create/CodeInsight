#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    int answer = 0;
    if (x == 1 && y == 1) {
        answer+=400000;
    }

    if (x == 1) {
        answer+=300000;
    } else if (x == 2) {
        answer+=200000;
    } else if (x == 3) {
        answer+=100000;
    }

    if (y == 1) {
        answer+=300000;
    } else if (y == 2) {
        answer+=200000;
    } else if (y == 3) {
        answer+=100000;
    }

    cout << answer << endl;
}