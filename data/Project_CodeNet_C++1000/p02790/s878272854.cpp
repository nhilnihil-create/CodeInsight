
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Main() {
    // input
    int a, b;
    cin >> a >> b;

    string ans;
    // process
    if (a < b) {
        for (int i = 0; i < b; i++) {
            ans += to_string(a);
        }
    } else {
        for (int i = 0; i < a; i++) {
            ans += to_string(b);
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
