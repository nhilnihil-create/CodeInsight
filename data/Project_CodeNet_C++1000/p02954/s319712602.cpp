#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s;
    cin >> s;
    s += 'R';
    int l = 0, r = 1, k;
    vector<int> ans(s.size());
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i-1]){
            if(s[i] == 'R') r++;
            else l++;
        }
        else{
            if(s[i] == 'R'){
                ans[k-1] += (r+1)/2 + l/2;
                ans[k] = r/2 + (l+1)/2;
                r = 1; l = 0;
            }
            else{
                l++;
                k = i;
            }
        }
    }

    rep(i,s.size()-1) cout << ans[i] << ' ';
}