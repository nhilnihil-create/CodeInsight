#include <iostream>

using namespace std;

int main() {
    long long h, n, a;
    cin >> h >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h -= a;
    }

    if (h <= 0)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    return 0;
}