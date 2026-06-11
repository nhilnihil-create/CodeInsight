#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int k,x;
    cin >> k >> x;
    for (int i = x - k + 1; i < x + k - 1; i++)cout << i << " ";
    cout << x + k - 1 << endl;
    return 0;
}
