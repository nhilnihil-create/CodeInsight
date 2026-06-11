#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;


template <class T>
ostream& operator<<(ostream& os, vector<T> v) {
    os << "{";
    for (int i = 0; i < v.size(); ++i) {
        if(i) os << ", ";
        os << v[i];
    }
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> p) {
    return os << "{" << p.first << ", " << p.second << "}";
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &&i : v) scanf("%d", &i), i--;
    vector<int> c(n);
    for (auto &&i : c) scanf("%d", &i);
    ll ans = -INF<int>;
    vector<int> visited(n);
    for (int i = 0; i < n; ++i) {
        if(visited[i]) continue;
        vector<int> a;
        a.emplace_back(i);
        a.emplace_back(v[i]);

        visited[i] = 1;
        visited[v[i]] = 1;
        while(a.back() != i){
            a.emplace_back(v[a.back()]);
            visited[a.back()] = 1;
        }
        a.pop_back();
        vector<ll> aa{0};
        ll S = 0;
        for (auto &&j : a) aa.emplace_back(aa.back()+c[j]), S += c[j];
        for (auto &&j : a) aa.emplace_back(aa.back()+c[j]);
        for (int j = 0; j < a.size(); ++j) {
            for (int l = 1; l <= min<int>(a.size(),k); ++l) {
                ans = max(ans, aa[j+l]-aa[j]);
            }
        }
        if(k/a.size()){
            for (int j = 0; j < a.size(); ++j) {
                for (int l = 0; l <= a.size(); ++l) {
                    ans = max(ans, aa[j+l]-aa[j]+(k-l)/(int)a.size()*S);
                }
            }
        }

    }
    cout << ans << "\n";
    return 0;
}