
#include <iostream>
#include <iomanip>
using namespace std;

void Main() {
    // input
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        if (A % 2 == 0) {
            if (!((A % 3 == 0) || (A % 5 == 0))) {
                cout << "DENIED";
                return;
            }
        }
    }

    cout << "APPROVED";
    


    // translate


    // output

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
