#include <iostream>

using namespace std;

int main() {
    int H1, M1, H2, M2, K, ans;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    ans = H2 * 60 + M2 - (H1 * 60 + M1);
    if (ans - K < 0) cout << 0 << endl;
    else cout << ans - K << endl;
    return 0;
}