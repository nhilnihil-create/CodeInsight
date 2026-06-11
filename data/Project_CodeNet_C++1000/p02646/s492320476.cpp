#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if (abs(A - B) <= T * (V - W)) cout << "YES";
    else cout << "NO";
    return 0;
}