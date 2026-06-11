#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    vector<bool> flg(n,false);
    vector<int> penalty(n);
    int ans = 0;
    rep(i,m){
        int p;
        string s;
        cin >> p >> s;
        p--;
        if(s=="AC" && flg[p]==false) {
            flg[p]=true;
            ans++;
        }
        else if(s=="WA" && flg[p]==false) penalty[p]++;
    }
    int ans_pnl = 0;
    rep(i,n){
        if(flg[i]==true) ans_pnl+=penalty[i];
    }
    cout << ans << " " << ans_pnl << endl;
    return 0;
}