#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    while (true) {
        bool is_prime = true;

        for (int i = 2, n = x; i < n; i++)
            if (x % i == 0) {
                is_prime = false;
                break;
            }

        if (is_prime)
            break;
        else
            x++;
    }


    cout << x << endl;
}