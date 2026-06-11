#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    cout << accumulate(p.begin(), p.begin() + k, 0);
}