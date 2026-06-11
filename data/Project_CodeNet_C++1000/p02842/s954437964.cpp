#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = n * 100; i <= n * 100 + 99; i++) {
        if (i % 108 == 0) {
            cout << i / 108 << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}