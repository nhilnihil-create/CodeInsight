#include <iostream>
using namespace std;

int main() {
    long long t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    if (t1 * a1 + t2 * a2 > t1 * b1 + t2 * b2) {
        swap(a1, b1);
        swap(a2, b2);
    }
    if (t1 * a1 + t2 * a2 == t1 * b1 + t2 * b2) {
        cout << "infinity";
    } else if (a1 < b1) {
        cout << 0;
    } else {
        long long top = t1 * (a1 - b1), bot = t1 * (b1 - a1) + t2 * (b2 - a2);
        long long result = 2 * (top / bot);
        if (top % bot != 0) {
            result++;
        }
        cout << result;
    }
    return 0;
}
