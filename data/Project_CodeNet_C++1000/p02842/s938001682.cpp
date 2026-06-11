#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n;
    double tax = 1.08;
    cin >> n;
    int before1 = n / tax;
    int before2 = ceil(n / tax);
    bool ans = true;
    if (int(before1 * tax) == n)cout << before1 << endl;
    else if (int(before2 * tax) == n)cout << before2 << endl;
    else cout << ":(" << endl;
    return 0;
}