#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a <= b + b) {
        cout << "0" << "\n";
    } else {
        cout << a - (b + b) << "\n";


    }
}













