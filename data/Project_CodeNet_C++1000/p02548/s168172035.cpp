#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    ll int count = 0;
    for(int i = 1; i < n; i++) {
        count += (n - 1) / i;
    }
    cout << count << '\n';
}