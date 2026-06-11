#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi a(n+1);
    rep(i, n-1) {
        int j;
        cin >> j;
        a.at(j)++;
    }
    for (int i = 1; i < n+1; i++) cout << a.at(i) << endl;
}