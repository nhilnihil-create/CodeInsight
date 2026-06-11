#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    sort(d.begin(), d.end());
    int k = n/2;
    cout << d[k] - d[k-1] << endl;
    return 0;
}