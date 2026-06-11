#include <iostream>

using namespace std;

int main(void)
{
    int D, T, S;

    cin >> D >> T >> S;

    int x = T * S;
    if (x >= D) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}