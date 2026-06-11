#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    vector<string> c;
    rep(i,n) cin >> s[i];
    sort(s.begin(), s.end()); 
    for(int i = 0; i < n; ++i){
        if(i == 0) c.push_back(s[i]);
        else{
            if(s[i] == s[i-1]) continue;
            else c.push_back(s[i]);
        }
    } 
    sort(c.begin(), c.end());
    int m = c.size();
    // rep(i,m) cout << c[i] << " ";
    // cout << endl;
    vector<int> ans(m);
    int j = 0;
    for(int i = 1; i < n; ++i){
        if(s[i] != s[i-1]) ++j;
        else ans[j]++;
    }
    int cnt = 0;
    rep(i,m){
        cnt = max(cnt, ans[i]);
    }
    cout << endl;
    rep(i,m){
        if(ans[i] == cnt) cout << c[i] << endl;
    }
    return 0;
}