#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    if (22 <= sum) cout << "bust" << endl;
    else cout << "win" << endl;
    return 0;
}