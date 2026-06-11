#include <iostream>
using namespace std;

int A, B;

void input() {
    cin >> A >> B;
}

void solve() {
    int ans;
    ans = ((B - 1) + (A - 1) - 1) / (A - 1);
    cout  << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}