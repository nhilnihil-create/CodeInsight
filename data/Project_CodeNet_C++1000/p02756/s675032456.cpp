#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
    string s;
    int n;
    cin >> s >> n;
    deque<char> data(all(s));
    int now = 0;
    rep(i, n) {
        int t;
        cin >> t;
        if (t == 1)
            now++;
        else {
            int F;
            char c;
            cin >> F >> c;
            if (F == 1) {
                if (now % 2 == 0)
                    data.push_front(c);
                else
                    data.push_back(c);
            } else {
                if (now % 2 == 1)
                    data.push_front(c);
                else
                    data.push_back(c);
            }
        }
    }
    if (now % 2 == 1) reverse(all(data));
    cout << string(all(data)) << endl;
}