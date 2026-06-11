#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll l,r,ans=1000000000;
    cin >> l >> r;
    if(r-l>=2020){
        cout << 0 << "\n";
        return 0;
    }else{
        for(ll i=l;i<r;++i){
            for(ll j=l+1;j<=r;++j){
                ll x=(i*j)%2019;
                ans=min(ans,x);
            }
        }
        cout << ans << "\n";
        return 0;
    }
}   