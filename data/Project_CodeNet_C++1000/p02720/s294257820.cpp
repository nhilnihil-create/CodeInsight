#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

bool dfs(ll keta, ll top, ll &total, vector<char> &chars, ll K) {
    if (total > K) {
        return true;
    }

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
    bool done = false;
    if (top > 0) {
        chars[keta] = (char)top + '0' - 1;
        done = done || dfs(keta - 1, top - 1, total, chars, K);
    }
    chars[keta] = (char)top + '0';
    done = done || dfs(keta - 1, top, total, chars, K);
    if (top < 9) {
        chars[keta] = (char)top + '0' + 1;
        done = done || dfs(keta - 1, top + 1, total, chars, K);
    }
    return done;
}
int main() {
    ll K;
    cin >> K;
    ll pretotal = 9;
    if (K <= 9) {
        print(K);
        return 0;
    }
    for (ll tketa = 2; true; tketa++) {
        vector<char> chars(tketa);
        for (ll ttop = 1; ttop <= 9; ttop++) {
            chars[tketa - 1] = ttop + '0';
            bool done = dfs(tketa - 2, ttop, pretotal, chars, K);
            if (done) {
                return 0;
            }
        }
    }
}
