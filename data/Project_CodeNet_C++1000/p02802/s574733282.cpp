#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> wa(n+1);
    vector<bool> ac(n+1, false);
    int ans_wa = 0, ans_ac = 0;
    rep(i,m){
        int p;
        string s;
        cin >> p >> s;
        if(s == "WA") wa[p]++;
        else{
            if(!ac[p]){
                ans_wa += wa[p];
                ac[p] = true;
                ans_ac++;
            }
        }
    }
    cout << ans_ac << ' ' << ans_wa << endl;
}