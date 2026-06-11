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
    int k; cin >> k;
    int chu = k / 2;
    vector<int> d(k);
    rep(i, k) cin >> d[i];
    sort(d.begin(), d.end());
    if(d[chu-1] == d[chu]) {
        cout << 0 << endl;
        return 0;
    }

    cout << d[chu] - d[chu-1] << endl;

    return 0;
}