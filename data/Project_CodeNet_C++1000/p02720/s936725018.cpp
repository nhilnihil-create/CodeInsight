#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

bool dfs(ll keta, ll top, ll &total, vector<char> &chars, ll K) {
    if (keta == -1) {
        total++;
        if (total == K) {
            for (ll s = chars.size() - 1; s >= 0; s--) {
                print0(chars[s]);
            }
            print();
            return true;
        }
        return false;
    }
    if (top > 0) {
        chars[keta] = (char)top + '0' - 1;
        if (dfs(keta - 1, top - 1, total, chars, K)){
            return true;
        }
    }
    chars[keta] = (char)top + '0';
    if (dfs(keta - 1, top, total, chars, K)) {
        return true;
    }
    if (top < 9) {
        chars[keta] = (char)top + '0' + 1;
        if (dfs(keta - 1, top + 1, total, chars, K)) {
            return true;
        }
    }
    return false;
}
int main() {
    ll K;
    cin >> K;
    ll total = 0;
    for (ll keta = 1; true; keta++) {
        vector<char> chars(keta);
        for (ll top = 1; top <= 9; top++) {
            chars[keta - 1] = top + '0';
            if (dfs(keta - 2, top, total, chars, K)) {
                return 0;
            }
        }
    }
}
