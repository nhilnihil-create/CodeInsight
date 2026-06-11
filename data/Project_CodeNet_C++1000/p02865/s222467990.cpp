#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = N / 2;
    if (N % 2 == 0) ans--;
    cout << ans << endl;
    return 0;
}
