#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;



int main() {
    string s, t; cin >> s >> t;
    int n = s.size();
    vector<vector<ll>> vec(30);
    for(ll i = 0ll; i < n; i++){
        int m = s[i] - 'a';
        vec.at(m).emplace_back(i);
    }
    ll res = 0ll;
    ll pointer = -1ll;
    rp(j, 0, int(t.size())) {
        int now_char = int(t[j] - 'a');
        if(int(vec.at(now_char).size()) == 0) {
            cout << -1 << endl;
            return 0;
        }
        else if(*(vec.at(now_char).end()-1) <= pointer) {
            res += n;
            pointer = *vec.at(now_char).begin();
        }
        else pointer = *upper_bound(vec.at(now_char).begin(), vec.at(now_char).end(), pointer);
    }
    res += pointer + 1;
    cout << res << endl;
    return 0;
}