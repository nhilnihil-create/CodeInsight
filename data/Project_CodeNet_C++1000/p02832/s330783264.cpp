#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    int idx = 1;
    int ans = 0;
    rep(i,n){
        if(a.at(i) == idx){
            idx++;
            continue;
        }
        ans++;
    }
    if(ans == n) cout << -1 << endl;
    else cout << ans << endl;
}