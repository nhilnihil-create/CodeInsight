#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<vector<int>> table(10, vector<int>(10, 0));
    rrep(i, n) {
        string s = to_string(i);
        int a = s[0] - '0', b = s.back() - '0';
        table[a][b]++;
    }

    ll ans = 0;
    rrep(i, n) {
        string s = to_string(i);
        int a = s[0] - '0', b = s.back() - '0';
        ans += table[b][a];
    }
    cout << ans << endl;
  
    return 0;
}