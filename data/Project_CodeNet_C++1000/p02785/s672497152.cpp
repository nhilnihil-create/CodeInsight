#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    sort(h.begin(),h.end());
    reverse(h.begin(),h.end());
    ll ans = 0;
    for(auto x : h){
        if(k-- > 0)continue;
        ans += x;
    } 
    cout << ans << endl;
}