
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    double L;
    cin >> L;


    // translate
    double ans = L * L * L / 27;


    // output
    cout << ans << endl;

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
