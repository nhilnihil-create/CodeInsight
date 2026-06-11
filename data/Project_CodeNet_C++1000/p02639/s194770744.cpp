#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 5; ++i) {
        int X; cin >> X;
        if (X == 0) cout << i + 1 << '\n';
    }
}
