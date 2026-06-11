#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int total{1}, cnt{0};
    while (total < b) {
        cnt++;
        // extend to a new power strip by adding a and subtract 1
        total = total + a - 1;
    }
    
    cout << cnt << endl;
}