#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    ll a;
    string bs;
    cin >> a >> bs;
    int b =
        (int)(bs[0] - '0') * 100 + (int)(bs[2] - '0') * 10 + (int)(bs[3] - '0');
    cout << a * b / 100 << endl;
    return 0;
}