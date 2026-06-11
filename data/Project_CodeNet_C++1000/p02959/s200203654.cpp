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
    
    int n;
    cin >> n;
    vector<ll> a(n+1),b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll ans=0,res=0;
    if(a[0]<=b[0]){
        ans+=a[0];
        res=b[0]-a[0];
    }else{
        ans+=b[0];
    }
    for(int i=1;i<n;++i){
        if(res>=a[i]){
            res=b[i];
            ans+=a[i];
        }else{
            ans+=res;
            a[i]-=res;
            if(a[i]<=b[i]){
                ans+=a[i];
                res=b[i]-a[i];
            }else{
                ans+=b[i];
                res=0;
            }
        }
    }
    if(res>=a[n]) ans+=a[n];
    else ans+=res;
    cout << ans << "\n";
    return 0;
}   