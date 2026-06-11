#include <iostream>

using namespace std;

int main() {
    char c; cin >> c;
    for (int i = 0; i < 26; i++) {
        if (c  == 'A' + i) {
            cout << "A" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (c == 'a' + i) {
            cout << 'a' << endl;
            return 0;
        }
    }
}