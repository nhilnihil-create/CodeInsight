#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    rep(i, n) cin >> v[i];
    sort(v.begin(), v.end());
    double p = (v[0] + v[1]) / 2;
    for(int i = 2; i < n; i++) p = (p + v[i]) / 2;
    cout << p << endl;
}

