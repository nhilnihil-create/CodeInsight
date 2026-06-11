#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, mx = 0, count = 0;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a == b) count++;
        else count = 0;
        mx = max(mx, count);
    }
    cout << (mx >= 3 ? "Yes" : "No");
}