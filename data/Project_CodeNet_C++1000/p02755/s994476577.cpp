
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Main() {
    // input
    int A, B;
    cin >> A >> B;


    // translate
    for (u_int64_t price = 1; price < 1010; price++) {
        if (floor(price * 0.08) == A && floor(price * 0.1) == B) {
            cout << price << endl;
            return;
        }
    }
    cout << -1 << endl;


    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
