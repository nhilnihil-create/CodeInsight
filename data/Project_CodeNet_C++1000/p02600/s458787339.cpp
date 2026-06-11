#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    int kyu = 8;
    for (size_t i = 400;; i += 200) {
        if (i <= x && x < i + 200) {
            cout << kyu << endl;
            return 0;
        }
        kyu--;
    }
}
