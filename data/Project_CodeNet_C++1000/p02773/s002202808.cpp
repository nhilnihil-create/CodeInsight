#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    map<string,int> m;
    rep(i,n){
        string s;
        cin >> s;
        m[s]++;
    }
    vector<vector<string>> ans(200005);
    int mi = 0;
    for(auto p : m){
        mi = max(mi, p.second);
        ans[p.second].push_back(p.first);
    }
    sort(ans[mi].begin(), ans[mi].end());
    for(auto p : ans[mi]) cout << p << endl;
}