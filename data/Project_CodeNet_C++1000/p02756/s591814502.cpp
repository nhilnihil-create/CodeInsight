#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    string s;
    cin >> s;
    deque<char> q;
    for (char c : s) q.push_back(c);
    bool flip = false;
    int Q;
    cin >> Q;
    rep(qi,Q) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            flip = !flip;
        }
        else {
            int f; char c;
            cin >> f >> c;
            if (flip) f = 3-f;
            if (f == 1) {
                q.push_front(c);
            }
            else {
                q.push_back(c);
            }
        }
    }
    if (flip) reverse(q.begin(), q.end());
    string ans;
    for (char c : q) ans += c;
    cout << ans << endl;
    return 0;
}