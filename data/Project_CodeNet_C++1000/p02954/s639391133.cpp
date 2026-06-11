#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    vector<int> border_rl(0);
    vector<int> border_lr(0);
    border_lr.push_back(-1);
    int len = S.size();
    vector<int> ans(len,0);
    rep(i,len - 1){
        if (S[i] == 'R' && S[i + 1] == 'L') border_rl.push_back(i);
        if (S[i] == 'L' && S[i + 1] == 'R') border_lr.push_back(i);
    }
    border_lr.push_back(len - 1);
    rep(i,border_rl.size()){
        if ((border_rl[i] - border_lr[i]) % 2 == 0){
            ans[border_rl[i]] += ((border_rl[i] - border_lr[i]) / 2);
            ans[border_rl[i] + 1] += ((border_rl[i] - border_lr[i]) / 2);
        }
        else{
            ans[border_rl[i]] += ((border_rl[i] - border_lr[i]) / 2 + 1);
            ans[border_rl[i] + 1] += ((border_rl[i] - border_lr[i]) / 2);
        }
        
        if ((border_lr[i + 1] - border_rl[i]) % 2 == 0){
            ans[border_rl[i]] += ((border_lr[i + 1] - border_rl[i]) / 2);
            ans[border_rl[i] + 1] += ((border_lr[i + 1] - border_rl[i]) / 2);
        }
        else{
            ans[border_rl[i]] += ((border_lr[i + 1] - border_rl[i]) / 2);
            ans[border_rl[i] + 1] += ((border_lr[i + 1] - border_rl[i]) / 2 + 1);
        }
    }
    rep(i,len){
        cout << ans[i] << " ";
    }
    cout << endl;
}
