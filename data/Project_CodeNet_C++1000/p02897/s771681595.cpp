#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    int bunbo = n;
    double bunshi;
    if (bunbo % 2 == 1) bunshi = (double) (n-1)/2 + 1;
    else if (bunbo % 2 == 0) bunshi = (double) n/2;

    cout << fixed << setprecision(15) << bunshi / bunbo << endl;

    return 0;
}