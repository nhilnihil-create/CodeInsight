#include <iostream>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;

    bool turn = true;
    while (0 < a && 0 < c) {
        if (turn) c -= b;
        else a -= d;
        turn = !turn;
    }

    cout << (a <= 0 ? "No" : "Yes") << endl;
}

