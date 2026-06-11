#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

#define fs first
#define sc second

int main() {
    int N, Q;
    cin >> N >> Q;
    ll d[N];
    for(int i = 0; i < N; i++) cin >> d[i];

    vector<ll> ans;

    for(int q = 0; q < Q; q++) {
        ll n, x, m;
        cin >> n >> x >> m;

        // <の数を数えたい
        // <の数 = n - 1 - (=の数) - (>の数)
        vector<ll> dm(N, 0);
        for(int i = 0; i < N; i++) {
            dm[i] = d[i] % m;
        }

        ll cnt_eq = 0;
        ll tmp = 0;
        for(int i = 0; i < N; i++) {
            if(dm[i] == 0) tmp++;
        }
        cnt_eq += (n - 1) / N * tmp;
        for(int i = 0; i < (n - 1) % N; i++) {
            if(dm[i] == 0) cnt_eq++;
        }

        ll cnt_left = 0;
        ll dn = x % m;
        tmp = 0;
        for(int i = 0; i < N; i++) {
            tmp += dm[i];
        }
        dn += (n - 1) / N * tmp;
        for(int i = 0; i < (n - 1) % N; i++) {
            dn += dm[i];
        }
        cnt_left = dn / m;

        //cout << cnt_eq << endl;
        //cout << cnt_left << endl;

        ans.push_back(n - 1 - cnt_eq - cnt_left);
    }

    for(ll val : ans) {
        cout << val << endl;
    }

    return 0;
}
