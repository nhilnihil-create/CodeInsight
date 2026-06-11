
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int S, W;
    cin >> S >> W;


    // translate


    // output
    if (W >= S) {
        cout << "unsafe" << endl;
    } else {
        cout << "safe" << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
