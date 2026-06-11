
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    if (a >= 1 && a <= 9 && b >= 1 && b <= 9) {
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

