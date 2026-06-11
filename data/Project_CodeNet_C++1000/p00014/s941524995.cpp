#include <iostream>

using namespace std;

int main() {
    for(int d; cin >> d;) {
        int sum {};
        for(int i = 0; i < 600; i += d) {
            sum += i * i * d;
        }
        cout << sum << endl;
    }

    return 0;
}