#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, X, T;
    cin >> N >> X >> T;
    for (int i = 1; i < 1e5 + 5; i++) {
        // X * 2 = 24 6 *2 = 12
        if(N <= X * i) {
            cout << T * i;
            break;
        }
    }
    return 0;
}
