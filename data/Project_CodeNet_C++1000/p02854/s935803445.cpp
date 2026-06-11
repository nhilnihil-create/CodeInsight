#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    ll n, a, dist = 100000000, mindist = 11111111100000, S;
    cin >> n;
    vector<ll>stick(n+1);
    stick[0] = 0;
    rep(i, n) {
        cin >> a;
        stick[i+1] = stick[i]+ a;
    }
    S = stick[n];
    stick.erase(stick.begin());

    rep(i, n-1) {
        mindist = min(mindist, abs(stick[i] - (S - stick[i])));
    }
    cout << mindist << endl;

    return 0;
}