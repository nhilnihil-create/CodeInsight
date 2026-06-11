#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;




int main(){
    int k, q;
    cin >> k >> q;
    vector<int> d(k);
    rep(i, k) {
        cin >> d[i];
    }
    vector<int> result;
    rep(i, q) {
        int n, x, m;
        cin >> n >> x >> m;
        int ans = n-1;
        vector<int> v(k);
        ll sum = 0;
        ll eq = 0;
        rep(j, k) {
            v[j] = d[j] % m;
            sum += v[j];
            if (v[j]==0) eq++;
        }
        ll fin;
        int num = (n-1)/k;
        fin = x+sum*num;
        int re = (n-1)%k;
        rep(j, re) {
            fin += v[j];
            if (v[j]==0) ans--;
        }
        ans -= eq*num;
        ans -= (fin/m-x/m);
        result.push_back(ans);
    }
    rep(i, result.size()) {
        cout << result[i] << endl;
    }
    return 0;
}
