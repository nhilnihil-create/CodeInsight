#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    string days[] = {"SUN", "MON","TUE","WED","THU","FRI","SAT"};
    rep(i, 7) {
        if (s == days[i]) {
            cout << 7 - i << endl;
            return 0;
           }
    }
    return 0;
}