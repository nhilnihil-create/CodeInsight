#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        if ( a == 0) {
            cout << i+1;
            break;
        }
    }
}
