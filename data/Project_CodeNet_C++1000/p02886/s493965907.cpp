#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++) cin >> d[i];

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            ans += d[i]*d[j];
        } 
    }

    cout << ans << endl;
}