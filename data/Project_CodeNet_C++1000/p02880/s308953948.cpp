#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    for (int i = 1; i < 10; i++) {
        if (n%i == 0 && 1 <= n/i && n/i <= 9) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
