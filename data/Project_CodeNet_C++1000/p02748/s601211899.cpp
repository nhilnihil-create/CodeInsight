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
const int inf = 1000000000; //10^9

int main(){
    int a, b, m;
    cin >> a >> b >> m;
    vector<int> A(a);
    vector<int> B(b);
    rep (i, a) cin >> A[i];
    rep (i, b) cin >> B[i];

    int ans = inf;
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        int p;
        p = A[x-1] + B[y-1] - c;

        ans = min(ans, p);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ans = min(ans, A[0] + B[0]);

    cout << ans << endl;

    return 0;
}