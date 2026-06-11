#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sub(n+1);
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        sub[boss]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << sub[i] << "\n";
    }
}