#include <iostream>
using namespace std;

int main() {
    int a, b; cin >> a >> b;

    for (int i = 1; i <= 1250; ++i) {
        if (int(i * 8 / 100.0) == a && int(i / 10.0) == b) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}

