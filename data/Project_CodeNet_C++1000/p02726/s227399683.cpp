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
const int MOD = 1000000007;

/* --------------------------------------------------- */


int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    
    vector<int> ans(n, 0);
    rep(i, n - 1) {
        forr(j, i + 1, n) {
            int l = min(abs(j - i), abs(x - i) + abs(y - j) + 1);
            l = min(l, abs(y - i) + abs(x - j) + 1);
            ans[l]++;
        }
    }
    rep(i, n) {
        if(i == 0) continue;
        cout << ans[i] << endl;
    }

    return 0;
}