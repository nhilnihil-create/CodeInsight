#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, ans;
    cin >> a >> b;
    ans = a - (b * 2);
    cout << (ans >= 0 ? ans : 0) << endl;
}
