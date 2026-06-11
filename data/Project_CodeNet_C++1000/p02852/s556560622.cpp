#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cur = n;
    vector<int> ans;
    while(cur > 0){
        if(cur-m <= 0){
            ans.push_back(cur);
            break;
        }
        bool no = true;
        for(int nex = m; nex > 0; nex--){
            if(s[cur-nex] == '0'){
                ans.push_back(nex);
                cur -= nex;
                no = false;
                break;
            }
        }
        if(no){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,ans.size()){
        cout << ans[ans.size()-1-i] << " ";
    }
    cout << endl;
    return 0;
}