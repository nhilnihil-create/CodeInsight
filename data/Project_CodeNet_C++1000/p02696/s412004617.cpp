
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Main() {
    // input
    u_int64_t A, B, N;
    cin >> A >> B >> N;

    // translate
    u_int64_t ans = 0;
    if (B == 1) {
        cout << 0 << endl;
        return;
    }

    if (N < B) {
        cout << (A * N) / B << endl;
        return;
    }

    for (u_int64_t x = B-1; x <= N; x += B) {
        u_int64_t num = (A * x) / B - A * (x / B);
        ans = max(ans, num);
    }


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
