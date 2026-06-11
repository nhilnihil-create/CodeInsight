
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    u_int64_t N;
    int K;
    cin >> N >> K;


    // translate
    int digit = 0;
    while (N > 0) {
        digit++;
        N /= K;
    }


    // output
    cout << digit << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
