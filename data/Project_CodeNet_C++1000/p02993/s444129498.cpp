#include <bits/stdc++.h>
#define PREP(i, s, x) for(ll i = (s); i < (x); i++)
#define MREP(i, s, x) for(ll i = (s); i >= (x); i--)
#define REP(i, x) PREP(i, 0, x)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

// variable -------------------------------------------

constexpr ll INF = (1ll << 59);
constexpr ll MOD = 1000000007ll;

// structure ------------------------------------------

// function -------------------------------------------

// main -----------------------------------------------

int main() {
    string s;
    cin >> s;
    REP(i, 3){
        if(s[i] == s[i+1]){
            cout << "Bad" << endl;
            return 0;
        }
    }
    cout << "Good" << endl;
    return 0;
}