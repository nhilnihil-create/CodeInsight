#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#include <map>
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using Graph = vector<vector<int>>;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int n, r;
    cin >> n >> r;
    if(n > 9){
        cout << r << endl;
    } else {
        cout << r + 100 * (10 - n) << endl;
    }
}

