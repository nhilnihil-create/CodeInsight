#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        if(i % 3 != 0 && i % 5 != 0)
          sum += i;
    }
    cout << sum << endl;
}