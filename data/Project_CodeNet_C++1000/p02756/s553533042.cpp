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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    deque<char> que;
    rep(i, (int)(s.size())) {
        que.push_back(s[i]);
    }
    bool rev_flg = false;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            rev_flg = !rev_flg;
        }
        else if (t == 2) {
            int f;
            cin >> f;
            char c;
            cin >> c;
            if (!rev_flg && f == 1 || rev_flg && f == 2) {
                que.push_front(c);
            }
            else {
                que.push_back(c);
            }
        }
    }
    while(!que.empty()) {
        if (rev_flg) {
            cout << que.back();
            que.pop_back();
        }
        else {
            cout << que.front();
            que.pop_front();
        }
    }
    cout << endl;
    return 0;
}
