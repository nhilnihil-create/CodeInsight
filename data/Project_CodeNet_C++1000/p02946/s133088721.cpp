#include <iostream>

using namespace std;

int main() {
    int k, x; cin >> k >> x;
    int start = x - k + 1, end = x + k - 1;
    for (int i = start; i <= end; ++i) {
        cout << i;
        if (i != end) {
            cout << " ";
        }
    }
    cout << endl;
}