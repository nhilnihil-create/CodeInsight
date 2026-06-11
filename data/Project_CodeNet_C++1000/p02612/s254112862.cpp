#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    while (true) {
        sum += 1000;
        if (sum >= n) {
            cout << sum - n << endl;
            break;
        }
    }
    return 0;
}