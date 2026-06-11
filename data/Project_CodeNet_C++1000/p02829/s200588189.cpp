#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int a, b, c;
    cin >> a >> b;
    if (a + b == 3) c = 3;
    if (a + b == 4) c = 2;
    if (a + b == 5) c = 1;
    cout << c << endl;
    return 0;
}