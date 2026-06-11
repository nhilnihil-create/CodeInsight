#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long s = 0;  
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            s += j;
        }
    }
    cout << s;
}
