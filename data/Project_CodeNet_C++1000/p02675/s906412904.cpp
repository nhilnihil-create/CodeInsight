#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x % 10 == 2 || x % 10 == 4 || x % 10 == 5 || x % 10 == 7 || x % 10 == 9) {
        cout << "hon";
    } else if (x % 10 == 0 || x % 10 == 1 || x % 10 == 6 || x % 10 == 8) {
        cout << "pon";
    } else {
        cout << "bon";
    }
}