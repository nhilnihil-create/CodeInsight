#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int a, b;
    cin >> a >> b;
    bool ans = 0;
    for (int i = 1; i < 1500; i++) {
        if (floor(i * 0.08) == a && floor(i * 0.1) == b) {
            cout << i << "\n";
            ans = 1;
            break;
        }
    }
    if (!ans) puts("-1");
}
