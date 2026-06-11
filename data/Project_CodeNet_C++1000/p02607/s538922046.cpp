#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if ((i+1)%2==1 && a%2==1)
            ans++;
    }
    cout << ans << endl;
}