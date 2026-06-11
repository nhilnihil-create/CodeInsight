#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = 100000000;
    REP(i,100){
        int now = 0;
        rep(j,n){
            now+=pow((i-x[j]),2);
        }
        ans = min(ans,now);
    }
    cout << ans << endl;
}