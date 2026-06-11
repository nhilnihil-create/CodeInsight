
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Main() {
    // input
    u_int64_t N, A, B;
    cin >> N >> A >> B;


    // translate
    u_int64_t count = N / (A + B) * A;
    N %= A + B;
    count += min(N, A);




    // output
    cout << count << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
