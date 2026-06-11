#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << min({a + b, b + c, a + c}) << '\n';
}
