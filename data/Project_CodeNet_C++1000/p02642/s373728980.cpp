#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int b[1000001]{};

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;

    REP(i, n) {
        cin >> a[i];
        b[a[i]]++;
        st.insert(a[i]);
    }

    bool flag[1000001]{};

    for (auto i : st) {
        for(int j = 2; j < 1000001; j++) {
            if (i * j >= 1000001) break;
            flag[i*j] = true;
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        if (b[a[i]] == 1 && !flag[a[i]]) res++;
    }

    cout << res << endl;
    return 0;
}