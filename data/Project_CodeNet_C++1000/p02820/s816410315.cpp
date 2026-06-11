#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
const long long INFLL = 1LL << 60;
const int INFINT = 1 << 30;
const long long MOD = 1e9 + 7;

char winhand(char h) {
    if(h == 'r') {
        return 'p';
    } else if(h == 'p') {
        return 's';
    } else {
        return 'r';
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    int R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P >> T;
    map<char, int> mp;
    mp['r'] = R;
    mp['s'] = S;
    mp['p'] = P;
    int score = 0, sc;
    char pre = 'x';

    for(int k = 0; k < K; k++) {
        sc = 0;
        pre = 'x';
        for(int n = k; n < N; n += K) {
            if(winhand(T.at(n)) != pre) {
                sc += mp.at(winhand(T.at(n)));
                pre = winhand(T.at(n));
            } else {
                if(n + K < N) {
                    pre = 'x';
                }
            }
        }
        score += sc;
    }
    cout << score << endl;
}