#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    string s,t;
    cin >> s>> t;
    string ans{};
    rep(i, t.size()){
        ans.push_back(t[i]);
    }
    rep(i, s.size()){
        ans.push_back(s[i]);
    }
    cout << ans << endl;
}