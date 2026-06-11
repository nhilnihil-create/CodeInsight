#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    vector<int> res(s.size());
    int p = 0;
    rep(i, s.size() - 1){
        if (s[i] == 'R' && s[i + 1] == 'R') p++;
        if (s[i] == 'R' && s[i + 1] == 'L'){
            p++;
            res[i] = p;
            p = 0;
        }
    }
    p = 0;
    for (int i = s.size() - 1; i > 0; i--){
        if (s[i] == 'L' && s[i - 1] == 'L') p++;
        if (s[i] == 'L' && s[i - 1] == 'R'){
            p++;
            res[i] = p;
            p = 0;
        }
    }
    vector<int> ans(s.size());
    rep(i, s.size() - 1){
        if (s[i] == 'R' && s[i + 1] == 'L'){
            ans[i + 1] = res[i] / 2 + (res[i + 1] + 1) / 2;
            ans[i] = res[i + 1] / 2 + (res[i] + 1) / 2;
        }
    }
    rep(i, ans.size()) cout << ans[i] << " ";
}