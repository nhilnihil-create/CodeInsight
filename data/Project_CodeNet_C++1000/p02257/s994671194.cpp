#include <iostream>
using namespace std;

int prime(int j) {
    if (j == 2) return 1;
    if (j % 2 == 0) return 0;
    for (int i = 3; i <= j / i; i += 2) {
        if (j % i == 0) return 0;
    }
    return 1;
}

int main() {

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        if (prime(j)) ++ans;
    }
    cout << ans << endl;

    return 0;
}