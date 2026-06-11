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

    string s;
    cin >> s;

    int n = s.size();

    vector<int> ans(n+1, 0);
    
    int cntR = 0, cntL = 0;
    for(int i = 0; i < n; i++) {
        if (s[i] == '<') cntR++;
        else cntR = 0;
        ans[i+1] = cntR;
    }
    for(int i = n-1; i >= 0; i--) {
        if (s[i] == '>') cntL++;
        else cntL = 0;
        ans[i] = max(cntL, ans[i]);
    }

    ll sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += ans[i];
    }

    cout << sum << endl;

    return 0;
}