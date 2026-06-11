#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = -1;
    int A, B;
    cin >> A >> B;
    int l = A / 10 + B / 10;
    if(l == 0)
        ans = A * B;
    cout << ans << endl;
}