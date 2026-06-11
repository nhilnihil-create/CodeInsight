#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int x;
    cin >> x;
    if (x % 100 <= 5 * (x / 100)) {
        cout << '1' << endl;
    }
    else {
        cout << '0' << endl;
    }
    return 0;
}