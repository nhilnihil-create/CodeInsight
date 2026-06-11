#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int L, R;
    cin >> L >> R;

    if (R - L >= 2019) {
        cout << 0 << endl;
        return 0;
    }

    int min = 9999;
    long long int tmp;
    for (long long int i = L; i < R; i++) {
        for (long long int j = i + 1; j <= R; j++) {
            tmp = i * j;
            tmp %= 2019;
            if (min > tmp) {
                min = tmp;
            }
        }
    }
    cout << min << endl;

    return 0;
}
