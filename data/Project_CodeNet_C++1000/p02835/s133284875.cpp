#include <iostream>
using namespace std;

int main() {
    int A1, A2, A3;

    cin >> A1 >> A2 >> A3;
    int allValues = (A1 + A2 + A3);

    if (allValues >= 22)
        cout << "bust" << endl;
    else
        cout << "win" << endl;

    return 0;
}