#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int A, B, C;
    cin >> A >> B >> C;
    ans = max(0, C - (A - B));

    cout << ans << endl;
}