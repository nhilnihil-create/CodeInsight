#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, X;  cin >> K >> X;
    for (int d = -K + 1; d < K; ++d) {
        cout << X + d << " ";
    }
    cout << endl;
}
