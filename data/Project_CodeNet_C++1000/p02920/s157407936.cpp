#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n;
    cin >> n;
    vector<int> s(1 << n);
    REP(i, 1 << n) cin >> s[i];
    
    int mx = 0;
    multiset<int> st1, st2;
    REP(i, 1 << n) {
        st1.insert(-s[i]);
        mx = max(mx, s[i]);
    }
    st1.erase(st1.find(-mx));
    st2.insert(-mx);
    REP(i, n) {
        multiset<int> st;
        for (int x: st2) {
            auto iter = st1.upper_bound(x);
            if (iter == st1.end()) {
                cout << "No\n";
                return 0;
            }
            st.insert(*iter);
            st1.erase(iter);
        }
        for (int x: st) st2.insert(x);
    }
    
    cout << "Yes\n";
    return 0;
}
