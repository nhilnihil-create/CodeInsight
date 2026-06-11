#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &p : v) {
        int a, b;
        cin >> a >> b;
        p = pii(a, b);
    }
    v.emplace_back(0, 1);

    bool exist = false;
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (v[i].first == v[i].second) cnt++;
        else {
            if (cnt >= 3) exist = true;
            cnt = 0;
        }
    }
    if (exist) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
