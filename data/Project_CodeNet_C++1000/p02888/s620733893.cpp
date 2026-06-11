#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    ll ans = 0;
    rep(i,n) for(int j = i+1; j < n; j++){
        auto itr = lower_bound(l.begin(), l.end(), l[i]+l[j]);
        ans += itr - l.begin() - 1 - j;
    }
    cout << ans << endl;
}