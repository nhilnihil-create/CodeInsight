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
    int m, d;
    cin >> m >> d;
    int ans = 0;
    rrep(i, m) {
        rrep(j, d) {
            int d1 = j % 10;
            int d10 = j / 10;
            if(!(d1 >= 2 && d10 >= 2)) continue;
            if(i == d1 * d10) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}