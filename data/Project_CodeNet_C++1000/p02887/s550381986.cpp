#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
string S;

void solve() {
    //cout.precision(10);
    cin >> N >> S;
    S.push_back('#');
    int ans = 0;
    for(int i = 0; i + 1 < S.size(); i++) {
        if(S[i] != S[i+1]) ans++;
    }
    cout << ans << endl;
    return;
}

int main() {
    solve();
    return 0;
}
