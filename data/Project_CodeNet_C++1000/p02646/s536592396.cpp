#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, V, W, T;
    cin >> A >> V >> B >> W >> T;
    if (V <= W) printf("NO\n");
    else printf("%s\n", T * (V - W) >= abs(A - B) ? "YES" : "NO");
    return 0;
}