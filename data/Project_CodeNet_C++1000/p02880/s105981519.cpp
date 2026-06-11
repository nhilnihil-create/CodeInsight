#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool check;
    for (int i = 1; i < 10; i++) {
        check = false;
        for (int j = 1; j < 10; j++) {
            if (n == i * j) {
                check = true;
                break;
            }
        }
        if (check == true) break;
    }

    if (check == true) cout << "Yes" << endl;
    else cout << "No" << endl;
}