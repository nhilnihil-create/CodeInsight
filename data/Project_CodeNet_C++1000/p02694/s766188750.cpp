#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    long long x;
    cin >> x;

    long long m = 100;
    int year = 0;
    while (m < x) {
        m += m / 100;
        ++year;
    }

    cout << year << endl;
    return 0;
}
