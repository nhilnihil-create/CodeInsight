#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int max_num = (n-1)*(n-2) / 2;
    if(k > max_num){
        cout << -1 << endl;
        return 0;
    }
    vector<P> v;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < i; j++){
            v.emplace_back(j+1, i+1);
        }
    }
    vector<P> ans;
    for(int i = 1; i < n; i++){
        ans.emplace_back(1, i+1);
    }
    for(int i = 0; i < max_num - k; i++){
        ans.push_back(v[i]);
    }
    cout << ans.size() << endl;
    for(P &p : ans){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}