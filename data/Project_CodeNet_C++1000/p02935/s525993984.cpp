#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];

    sort(v.begin(), v.end());

    double t = v[0];
    rep(i,n-1) {
        t = double(t + v[i+1]) /2;
    }

    printf("%.8f\n", t);
    return 0;
}