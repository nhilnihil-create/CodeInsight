#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    int ans = 0;
    rep(i,n) cin >> h.at(i);
    rep(i,n)if(h.at(i) >= k)ans++;
    cout << ans << endl;
}