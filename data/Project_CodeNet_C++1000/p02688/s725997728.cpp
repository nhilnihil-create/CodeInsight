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

int main() {

    int n, k;
    cin >> n >> k;
    
    vector<bool> snuke(n, false);

    for(int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for(int j = 0; j < d; j++) {
            int A;
            cin >> A;
            snuke[A-1] = true;
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        if (snuke[i] == false) res++;
    }

    cout << res << endl;
    return 0;
}