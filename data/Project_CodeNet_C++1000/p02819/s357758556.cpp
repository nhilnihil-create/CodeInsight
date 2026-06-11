#include <bits/stdc++.h>
using namespace std;

bool my_sqrt(int x) {
    for (int i = 2; i <= sqrt(x); i++) 
        if (x % i == 0) return false;

    return true;
}

int main () {
    int x;
    cin >> x;

    int r = 0;
    while (r == 0) {
        if (my_sqrt(x)) {
            r = x;
        } else {
            x++;
        }
    }

    cout << r << endl;

    return 0;
}
