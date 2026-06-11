#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    int k;
    cin >> k;
    int a = 0;
    for (int i = 0; i <= k; ++i) {
        a = (10 * a + 7) % k;
        if (a == 0){
            cout << 1 + i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}