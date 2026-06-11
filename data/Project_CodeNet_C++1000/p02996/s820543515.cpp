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
    
    int n,pr=0;
    cin >> n;
    vector<P> p(n);
    rep(i,n) cin >> p[i].second >> p[i].first;
    sort(p.begin(),p.end());
    rep(i,n){
        pr+=p[i].second;
        if(pr>p[i].first){
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    return 0;
}   