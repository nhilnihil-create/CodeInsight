#include <bits/stdc++.h>
using namespace std;
int main() {
    string A, B;
    cin >> A >> B;
    int len = A.size();
    int ans = 0;
    for (int i = 0; i < len; i++)
        ans += A[i] != B[i];
    cout << ans << '\n';
    return 0;
}