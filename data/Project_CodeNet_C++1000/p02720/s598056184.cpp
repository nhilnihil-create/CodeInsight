#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on

ll pow(ll x, ll n) {
    if (n == 0) {
        return 1;
    }
    ll res = pow(x * x, n / 2);
    if (n & 1) {
        res = res * x;
    }
    return res;
}

// dfs(0, ttop, chars, pretotal);
void dfs(ll keta, ll top, ll &total, vector<char> &chars, ll K) {
    if (total > K) {
        return;
    }

    if (keta == -1) {
        total++;
        if (total == K) {
            for (ll s = chars.size() - 1; s >= 0; s--) {
                print0(chars[s]);
            }
            print();
        }
        return;
    }
    if (top > 0) {
        chars[keta] = (char)top + '0' - 1;
        dfs(keta - 1, top - 1, total, chars, K);
    }
    chars[keta] = (char)top + '0';
    dfs(keta - 1, top, total, chars, K);
    if (top < 9) {
        chars[keta] = (char)top + '0' + 1;
        dfs(keta - 1, top + 1, total, chars, K);
    }
}
int main() {
    ll K;
    cin >> K;
    vector<vector<ll>> rr(100000, vector<ll>(10, 0));
    ll total = 0;
    for (ll top = 1; top <= 9; top++) {
        rr[1][top] = 1;
        total += 1;
    }
    if (K <= 9) {
        print(K);
        return 0;
    }
    ll tketa = -1;
    ll ttop = -1;
    ll pretotal = 9;

    rr[1][0] = 1;
    for (ll keta = 2; true; keta++) {
        for (ll top = 1; top <= 9; top++) {
            if (top == 1) {
                rr[keta][top] = rr[keta - 1][top] + rr[keta - 1][top + 1] + rr[keta - 1][0];
                total += rr[keta][top];
            } else if (top == 9) {
                rr[keta][top] = rr[keta - 1][top - 1] + rr[keta - 1][top];
                total += rr[keta][top];
            } else {
                rr[keta][top] = rr[keta - 1][top - 1] + rr[keta - 1][top] + rr[keta - 1][top + 1];
                total += rr[keta][top];
            }
            if (total >= K) {
                tketa = keta;
                ttop = top;
                break;
            }
            pretotal = total;
        }
        rr[keta][0] = rr[keta - 1][0] + rr[keta - 1][1];
        if (tketa >= 0) {
            break;
        }
    }
    vector<char> chars(tketa);
    //    dfs(0, ttop, chars, pretotal);

    chars[tketa - 1] = ttop + '0';
    dfs(tketa - 2, ttop, pretotal, chars, K);
}
