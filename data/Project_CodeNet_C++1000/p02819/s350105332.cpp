#include <bits/stdc++.h>

using namespace std;

int sosuu(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    while (sosuu(x) == false) {
        x++;
    }
    cout << x << endl;
    return 0;
}
