#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

int main(){
    int x, y;
    cin >> x >> y;
    bool flag = false;
    for (int i = 0; i <= x; ++i) {
        if (y == i * 2 + (x - i) * 4){
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}