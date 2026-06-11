#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = ;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;



int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    multiset <int> s;
    for(i = 0; i < (1 << n); i++) {
        cin >> x;
        s.insert(x);
    }

    multiset <int> sol;
    sol.insert(*prev(s.end()));
    s.erase(prev(s.end()));

    for(i = 0; i < n; i++) {
        vector <int> aux;
        for(auto it : sol) {
            auto cur = s.lower_bound(it);
            if(cur == s.end()) {
                cur = prev(cur);
            }
            while(cur != s.begin() && *cur >= it) {
                cur = prev(cur);
            }
            if(*cur >= it) {
                cout << "No";
                return 0;
            }
            aux.push_back(*cur);
            s.erase(cur);
        }
        for(auto it : aux) {
            sol.insert(it);
        }
    }

    cout << "Yes";

    return 0;
}
