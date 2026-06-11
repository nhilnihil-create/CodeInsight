#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1007;

bool used[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s;
    cin >> s;
    int k;
    cin >> k;

    bool c = 1;
    for (int i = 0; i + 1 < s.size(); ++i)
        c &= s[i] == s[i + 1];
    if (c) {
        int len = s.size() * k;
        cout << len / 2 << endl;
    }   
    else {
        if (s[0] != s.back()) {
            int ans = 0;
            for (int i = 0; i + 1 < s.size(); ++i) {
                if (s[i] == s[i + 1]) {
                    ++i;
                    ++ans;
                }   
            }   
            cout << ans * k << endl;
        }   
        else {
            vector <int> seg;
            int cur = 1;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != s[i - 1]) {
                    seg.app(cur);
                    cur = 1;
                }   
                else {
                    ++cur;
                }
            }
            seg.app(cur);

            int ans = 0;
            for (int i = 1; i < seg.size() - 1; ++i) {
                ans += (seg[i] / 2) * k;
            }   
            ans += seg[0] / 2;
            ans += seg.back() / 2;
            ans += ((seg[0] + seg.back()) / 2) * (k - 1);

            cout << ans << endl;
        }   
    }   

}