#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    cin >> num;

    for (long long i = -200; i <= 200; i++) {
        for (long long j = -200; j <= 200; j++) {
            if (i * i * i * i * i - j * j * j * j * j == num) {
                cout << i << " " <<j;
                return 0;
            }
        }
    }

    cout << "No";
    //
}
