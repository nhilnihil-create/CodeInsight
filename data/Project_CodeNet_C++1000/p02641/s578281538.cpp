#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    int x, n;
    cin >> x >> n;
    bool checked[110] = {};
    int p;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        checked[p] = true;
    }

    int res;
    for (int i = 0; i < 100; ++i) {
        if (x - i < 1){
            res = x - i;
            break;
        }
        if (!checked[x-i]){
            res = x - i;
            break;
        }
        if (x + i > 100){
            res = x + i;
            break;
        }
        if (!checked[x+i]){
            res = x + i;
            break;
        }
    }
    cout << res << endl;
}