#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int64_t A, V, B, W, T;
    cin >> A >> V >> B >> W >> T;
    if(abs(A-B) <= (V-W) * T) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
