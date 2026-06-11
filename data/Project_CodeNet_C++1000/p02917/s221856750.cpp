#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, last = INT_MAX;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int cur;
        cin >> cur;
        sum += min(last, cur);
        last = cur;
    }
    cout << sum + last << endl;
}

