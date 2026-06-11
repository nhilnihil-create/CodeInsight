
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void Main() {
    // input
    string S;
    cin >> S;


    // translate


    // output
    if ((S[2] == S[3]) && (S[4] == S[5])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
