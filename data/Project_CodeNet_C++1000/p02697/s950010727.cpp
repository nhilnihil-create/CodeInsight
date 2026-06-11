#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)

void chmax(ll& a, ll b) { a = max(a, b); }
void chmin(ll& a, ll b) { a = min(a, b); }

int main() {
    int n,m; cin >> n >> m;

    int i = 0;
    if(n%2 == 1) {
        for(int l=1, r=n-1; l < r; l++, r--) {
            if(i >= m) break;
            printf("%d %d\n", l, r);
            i++;
        }
    } else {
        bool flag = false;
        for(int l=1, r=n-1; l < r; l++, r--) {
            if(i >= m) break;
            // 対角線を超えた段階でずらさないといけない
            if(r-l <= n/2 && !flag) {
                l++;
                flag = true;
            }
            printf("%d %d\n", l, r);
            i++;
        }
    }
    return 0;
}
