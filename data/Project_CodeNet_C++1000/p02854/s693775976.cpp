#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> bar(n);
    for (int i = 0; i < n; i++) {
        cin >> bar.at(i);
    }
    ll sum = accumulate(bar.begin(), bar.end(), 0LL);
    ll acc = 0; ll min_p = sum;

    for (int i = 0; i < n; i++) {
        acc += bar.at(i);
        min_p = min(min_p, abs(acc-(sum-acc)));
    }
    cout << min_p << endl;
    return 0;
}