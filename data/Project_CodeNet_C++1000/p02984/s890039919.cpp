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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> ans(n,0);
    ans[0]=a[0];
    for(int i=1;i<n;++i){
        if(i%2==1 || i==1) ans[0]-=a[i];
        else ans[0]+=a[i];
    }
    for(int i=1;i<n;++i){
        ans[i]=2*(a[i-1]-(ans[i-1]/2));
    }
    rep(i,n){
        cout << ans[i] << "\n";
    }
    return 0;
}   