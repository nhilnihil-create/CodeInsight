#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

vector<pair<ll, int>> findFactor(ll n) {
    vector<pair<ll, int>> v;
    for (ll i = 2; i <= sqrt(n); i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        if (cnt > 0)
            v.emplace_back(i, cnt);
    }
    if (n > 1)
        v.emplace_back(n, 1);
    return v;
}

int main()
{
    ll n;
    cin >> n;
    int cnt = 0;
    for (const auto p : findFactor(n)) {
        // cout << p.first << " " << p.second << endl;
        int i = 1, sum = 1;
        while (sum <= p.second) {
            i++;
            sum += i;
        }
        cnt += i - 1;
    }
    cout << cnt << endl;
    return 0;
}