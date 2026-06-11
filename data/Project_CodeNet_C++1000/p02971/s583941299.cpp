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
    vector<int> a(n),b(n);
    rep(i,n){
        int x; cin >> x;
        a[i]=b[i]=x;
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    if(b[0]==b[1]){
        rep(i,n) cout << b[0] << "\n";
    }
    if(b[0]==b[1]) return 0;
    int maxi;
    rep(i,n){
        if(a[i]==b[0]) maxi=i;
    }
    rep(i,n){
        if(i!=maxi){
            cout << b[0] << "\n";
        }else{
            cout << b[1] << "\n";
        }
    }
    return 0;
}   