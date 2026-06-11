#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char last = '-', current;
    int n, sum = 0;
    cin >> n;
    cin.get();
    for (int i = 0; i < n; i++) {
        cin.get(current);
        if (current != last) {
            last = current;
            sum++;
        }
    }
    cout << sum;
}