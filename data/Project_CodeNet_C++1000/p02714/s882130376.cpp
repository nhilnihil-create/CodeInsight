
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Main() {
    // input
    int N;
    string S;
    cin >> N;
    cin >> S;


    // translate
    u_int64_t r = 0;
    u_int64_t g = 0;
    u_int64_t b = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'R') {
            r++;
        } else if (S[i] == 'G') {
            g++;
        } else {
            b++;
        }
    }
    u_int64_t ans = r * g * b;

    for (int D = 1; D < N / 2 + 1; D++) {
        for (int i = 0; i + 2 * D < N; i++) {
            if((S[i] - S[i+D]) * (S[i+D] - S[i+D+D]) * (S[i+D+D]-S[i]) != 0) {
                if (ans == 0) {

                } else {
                    ans--;
                }
            }
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
