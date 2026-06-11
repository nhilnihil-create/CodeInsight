#include <bits/stdc++.h>
using namespace std;

#define newline '\n'
#define IOS ios_base::sync_with_stdio(false); cin.tie(0)
using ll = long long;
using ull = unsigned long long;

int main() {
    IOS;

    int n;
    cin >> n;

    int m = n % 10;
    if (m == 3) {
        cout << "bon" << newline;
    } else if (m == 0 || m == 1 || m == 6 || m == 8) {
        cout << "pon\n";
    } else {
        cout << "hon\n";
    }

    return 0;
}