
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    a -= b;
    cout << max(0, c - a) << endl;

    return 0;
}

