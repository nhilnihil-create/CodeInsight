#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;

int main(){
    int n; cin >> n;
    vector<double> v(n);
    rep (i, n) cin >> v[i];
    sort(v.begin(), v.end());
    double vi = (v[0] + v[1]) / 2;
    for (int i = 2; i < n; i++) {
        vi = (vi + v[i]) / 2;
    }

    cout << vi << endl;

    return 0;
}