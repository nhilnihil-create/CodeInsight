#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    rep(i,k){
        int d;
        cin >> d;
        vector<int> a(d);
        rep(i,d) cin >> a.at(i);
        rep(i,d){
            rep(j,n+1){
                if(a.at(i) == j+1) num.at(j)++;
            }
        }
    }
    int ans = 0;
    rep(i,n){
        if(num.at(i) == 0) ans++;
    }
    cout << ans << endl;
}
