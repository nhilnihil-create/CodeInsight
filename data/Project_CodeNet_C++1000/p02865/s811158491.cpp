#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, N1, N2;
    cin >> N;
    int ans = 0;
    for (int N1 = 1; N1 < N; N1++) {
        N2 = N - N1;
        if (N1 >= N2) {
            break;
        }
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
