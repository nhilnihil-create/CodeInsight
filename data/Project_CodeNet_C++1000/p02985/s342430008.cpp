#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll mod = pow(10, 9) + 7LL;

    ll N, K;
    cin >> N >> K;

    vector<bool> b(N);
    vector<vector<int> > v(N);

    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    ll ans = K;

    stack<int> s;

    b[0] = true;

    if(K - 1 < v[0].size()) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = K - 1; i > K - 1 - v[0].size(); i--) {
        ans *= i;
        ans %= mod;
    }

    for(int i = 0; i < v[0].size(); i++) {
        b[v[0][i]] = true;
        s.push(v[0][i]);
    }

    while(!s.empty()) {
        int a = s.top();
        s.pop();

        if(K - 1 < v[a].size()) {
            cout << 0 << endl;
            return 0;
        }

        for(int i = K - 2; i > K - 1 - v[a].size(); i--) {
            ans *= i;
            ans %= mod;
        }

        for(int i = 0; i < v[a].size(); i++) {
            if(b[v[a][i]]) continue;
            b[v[a][i]] = true;
            s.push(v[a][i]);
        }
    }

    cout << ans << endl;
}