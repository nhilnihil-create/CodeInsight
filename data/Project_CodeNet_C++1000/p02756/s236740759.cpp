#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    int q;
    cin >> s >> q;
    bool rev_flg = false;
    deque<char> d;
    int n = s.size();
    rep(i, n) d.push_back(s[i]);
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            rev_flg = !rev_flg;
        }
        else if (t == 2) {
            int f;
            char c;
            cin >> f >> c;
            if ((f == 1) && !rev_flg || (f == 2) && rev_flg) {
                d.push_front(c);
            }
            else if ((f == 1) && rev_flg || (f == 2) && !rev_flg) {
                d.push_back(c);
            }
        }
    }
    if (rev_flg) {
        reverse(d.begin(), d.end());
    }
    for (auto dd: d) {
        cout << dd;
    }
    cout << endl;
    return 0;
}
