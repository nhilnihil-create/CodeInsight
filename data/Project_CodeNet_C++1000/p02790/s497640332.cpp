#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string A = string(b, '0' + a);
    string B = string(a, '0' + b);
    string ans = min(A, B);
    cout << ans << endl;
    return 0;
}