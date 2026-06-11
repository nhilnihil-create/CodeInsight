#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    bool found = false;
    for (int i = 1; i <= 9; ++i) {
        if (found) {
            break;
        }
        for (int j = 1; j <= 9; ++j) {
            if (i * j == n) {
                found = true;
                break;
            }
        }
    }

    cout << (found ? "Yes\n" : "No\n");
}