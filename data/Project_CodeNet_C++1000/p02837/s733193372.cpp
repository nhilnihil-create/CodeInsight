#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)



int main(){
    int n;
    cin >> n;
    vector<vector<P>> A(n);
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            int x,y;
            cin >> x >> y;
            x--;
            A[i].emplace_back(x,y);
        }
    }
    ll ans = 0;
    
    rep(is, 1 << n){
        ll cnt = 0;
        vector<int> res(n,0);
        bool isOk = true;
        rep(i,n){
            if(!(is >> i & 1)) continue;
            cnt++;
            res[i] = 1;
        }
        rep(i,n){
            if(!(is >> i & 1)) continue;
            vector<P> t = A[i];
            rep(j,t.size()){
                int f = t[j].first;
                int s = t[j].second;
                if(res[f] != s) isOk = false;
            }
        }
        
        if(isOk) ans = max(ans, cnt);
    }
    cout << ans << endl;
}
