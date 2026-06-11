#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)return 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (1 <= i&&i <= a - 2 && 1 <= j&&j <= b - 2)cout << '.';
                else cout << '#';
            }
            cout << endl;
        }
        cout << endl;
    }
}
