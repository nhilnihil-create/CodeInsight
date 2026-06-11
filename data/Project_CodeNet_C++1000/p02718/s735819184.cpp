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

    int n, m;
    cin >> n >> m;
    
    vector<double> a(n);
    double sum = 0;
    REP(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    int tmp = 0;

    REP(i, n) {
        if (a[i] >= sum*1/(4*m)) {
            tmp++;
        }
    }

    if (tmp >= m) {
        cout << "Yes" << endl;
        
    } else { 
        cout << "No" << endl;
        
    }

    //cout << ans << endl;
    return 0;
}