#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    ll num = 0;
    while (n)
        n = n / k, num++;
    cout << num << endl;
}