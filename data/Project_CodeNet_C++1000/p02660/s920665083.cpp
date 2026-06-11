#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    map<long long, int> powers;
    int ans = 0;

    for (long long i = 2; i * i <= n; i++)
        while (n % i == 0)
            n /= i, powers[i]++;
    if (n > 1)
        powers[n]++;

    for (auto x : powers) {
        int power = x.second;
        for (int i = 1; power - i >= 0; i++)
            power -= i, ans++;
    }
    cout << ans << "\n";
}