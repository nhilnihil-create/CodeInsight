
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define ll long long int
#define repeat(n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()

int main() {
    int n, m;
    cin >> n >> m;
    
    if (m % 2 == 0) {
        repeat(m / 2) {
            if (i != 0) cout << endl;
            cout << i + 1 << " " << m - i + 1 << endl;
            cout << m + i + 2 << " " << 2 * m - i + 1;
        }
    } else {
        repeat(m / 2) {
            cout << i + 1 << " " << m - i<< endl;
            cout << m + i + 1 << " " << 2 * m - i + 1 << endl;
        }
        cout << m + m / 2 + 1 << " " << 2 * m - m / 2 + 1;
    }

    return 0;
}
