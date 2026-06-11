#include <bits/stdc++.h>

using namespace std;

int main() {
    int phi;
    cin >> phi;
    for (int i = 1; i <= 360; ++i)  {
        if ((i * phi) % 360 == 0) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
