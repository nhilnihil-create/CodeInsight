
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int64_t N;
    cin >> N;

    // translate
    u_int64_t ans = 0;
    for (u_int64_t i = 1; i <= N; i++) {
        if (!(i % 3 == 0 || i % 5 == 0)) {
            ans += i;
        }
    }


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
