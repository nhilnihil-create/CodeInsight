#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void dfs(ll N, string s, char max) {
    if(s.length() == N) {
        cout << s << endl;
    } else {
        for(char add = 'a'; add <= max + 1; ++add) {
            dfs(N, s + add, (add < max) ? max : add);
        }
    }
}

int main() {
    ll N;
    cin >> N;

    dfs(N, "a", 'a');

    return 0;
}