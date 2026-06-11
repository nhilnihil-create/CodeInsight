#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    map<char,int> score;
    score['r'] = p;
    score['s'] = r;
    score['p'] = s;
    vector<bool> win(n, false);
    int ans = 0;
    rep(i,n){
        if(i < k){
            ans += score[t[i]];
            win[i] = true;
        }
        else{
            if(t[i-k] == t[i]){
                if(win[i-k]) win[i] = false;
                else{
                    win[i] = true;
                    ans += score[t[i]];
                }
            }
            else{
                ans += score[t[i]];
                win[i] = true;
            }
        }
    }
    cout << ans << endl;
}