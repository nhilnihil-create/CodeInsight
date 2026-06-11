#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = 1;
    int sum = a;
    if (b == 1) {
        cout << 0 << endl;
    }
    else {
        while(sum < b) {
            sum--;
            sum += a;
            ans++;
        }
        cout << ans << endl;
    }
}
