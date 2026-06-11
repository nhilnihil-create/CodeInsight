#include <iostream>
using namespace std;
int arry[33] = {0, 1, 1, 1, 2, 1, 2, 1,  5, 2, 2, 1, 5, 1, 2, 1, 14,
                1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main() {
    int k;
    while (cin >> k) {
        cout << arry[k] << endl;
    }
    return 0;
}