#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n,ans;
    cin >> n;
    ans = (n % 2 == 0) ? (n / 2) - 1 : n / 2;
    cout << ans << endl;
    return 0;
}
