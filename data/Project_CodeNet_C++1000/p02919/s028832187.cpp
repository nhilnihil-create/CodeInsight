#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
    return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
    int n; cin >> n;
    vector<ll> p(n);

    REP(i, n) cin >> p[i];

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);

    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return p[i - 1] > p[j - 1];
    });

    multiset<int> s; ll ans = 0;
    REP(i, 2) {
        s.insert(0); s.insert(n + 1);
    }
    
    for (int i : ord) {
        auto itr = s.upper_bound(i);
        auto w = *prev(itr, 2), x = *prev(itr), y = *itr,  z = *next(itr);
        
        ans += p[i - 1] * ((i - x) * (z - y) + (x - w) * (y - i));

        s.insert(i);
    }

    cout << ans << endl;

    return 0;
}
