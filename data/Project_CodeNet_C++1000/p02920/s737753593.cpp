#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int n;
    cin >> n;
    int ns = 1 << n;
    vl s(ns);
    multiset<int> allslimes;
    for (int i = 0; i < ns; ++i) {
        cin >> s[i];
        allslimes.insert(s[i]);
    }
    sort(s.begin(), s.end());
    multiset<int> slimes;
    slimes.insert(s[ns - 1]);
    allslimes.erase(prev(allslimes.end())); // largest
    for (int i = 0; i < n; ++i) {
        vi temp;
        for (auto it = slimes.rbegin(); it != slimes.rend(); it = next(it)) {
            auto ita = allslimes.lower_bound(*it);
            if (ita == allslimes.begin()) {
                cout << "No"
                     << "\n";
                return 0;
            }
            ita = prev(ita);
            temp.push_back(*ita);
            allslimes.erase(ita);
        }
        for (auto &t : temp) {
            slimes.insert(t);
        }
    }
    cout << "Yes"
         << "\n";
    return 0;
}