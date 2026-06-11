#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x, m = 100;
    cin >> x;
    int i;
    for (i = 1; ; ++i) {
        m += m / 100;
        if (m >= x)
            break;
    }
    cout << i << endl;

}
