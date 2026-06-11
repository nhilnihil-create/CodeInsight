#include <iostream>
using namespace std;

int main() {
    int N, C;

    cin >> N;

    C = N % 10;

    if (C == 2 || C == 4 || C == 5 || C == 7 || C == 9) {
        cout << "hon" << endl;
    } else if (C == 3) {
        cout << "bon" << endl;
    } else {
        cout << "pon" << endl;
    }

    return 0;
}
