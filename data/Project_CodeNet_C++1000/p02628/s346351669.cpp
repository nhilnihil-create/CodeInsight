#define ll long long int

#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> vc;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        vc.push_back(x);
    }
    sort(vc.begin(), vc.end());
    ll sum = 0;
    for (int i = 0; i < k; i++)sum += vc[i];
    cout << sum << endl;
    return 0;
}