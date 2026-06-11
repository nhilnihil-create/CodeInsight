#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iomanip>
#include <map>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
#include <string>
#include <limits>

using namespace std;

using i64 = int64_t;
using P = pair<i64, i64>;
i64 mod = 1000000007;
//i64 mod = 998244353;
int int_max = 2147483647;
i64 INF = 1e16;
int max_n = 1e5;

int main(int argc, char **argv) {
    string s, t;
    cin >> s >> t;
    vector<vector<i64>> mp(s.size()+1, vector<i64>(26, -1));
    //cout << s.size() <<" " << t.size() << endl;

    vector<set<i64>> v(26);

    for (i64 i=0; i<s.size(); ++i) {
        char c = s[i]-'a';
        v[c].insert(i+1);
    }

    for (i64 i=0; i<=s.size(); ++i) {
        for (char c2=0; c2<26; ++c2) {
            if (v[c2].empty()) {
                mp[i][c2] = -1;
            }
            auto it = v[c2].upper_bound(i);
            if (it == v[c2].end()) {
                mp[i][c2] = mp[0][c2];
            } else {
                mp[i][c2] = *it;
            }
        }
    }
    /*
    for (auto m: mp) {
        for (auto m2 :m) {
            cout << m2 << " ";
        }
        cout <<endl;
    }
    */
    i64 ans = 0;
    i64 curr = 0;
    for (char c : t) {
        //cout << curr << " " << ans <<endl;
        i64 next = mp[curr][c-'a'];
        if (next == -1) {
            cout << -1 << endl;
            return 0;
        }
        if (next <= curr) ++ans;
        curr = next;
    }

    cout << (ans*s.size()+curr) << endl;
    return 0;
}
