#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll output = 0;
    ll div = 10;
    if (N % 2 == 0) {
        while (div <= N) {
            output += N / div;
            div *= 5;
        }
        cout << output << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
