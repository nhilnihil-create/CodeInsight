#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, sum;

bool valid() {
    return (a + b) % 2 == 0;
}

bool kiri() {
    return (a - 1) <= (n - b);
}

void solve() {
    cin >> n >> a >> b;
    sum = 0;
    if(valid()) cout << b - ((a + b) / 2) << "\n";
    else if(kiri()) {
        b -= (a - 1);
        sum += (a - 1);
        a = 1;
        b--;
        sum++;
        sum += (b - ((a + b) / 2));
        cout << sum << "\n";
    } else {
        a += (n - b);
        sum += (n - b);
        b = n;
        a++;
        sum++;
        sum += (b - ((a + b) / 2));
        cout << sum << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}