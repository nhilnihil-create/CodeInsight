#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using G = vector<vector<int>>;
    
int main(){
    int n;
    cin >> n;
    ll v = 0;
    rep(i,n){
        v += (ll)(n-i) * (1+i);
    }
    
    ll e = 0;
    rep(i,n-1){
        int from, to;
        cin >> from >> to;
        if(from>to){
            swap(from, to);
        }
        e += (ll)from * (n-to+1);
    }
    ll ans = v - e;
    cout << ans << endl;
    return 0;
}