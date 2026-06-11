#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    for (int i = 1; i <= 1000; i++) {
        int x = i * 0.08;
        int y = i * 0.1;
        if (x == A && y == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}