#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> ans(n+1,-1);
    bool fl = true;
    rep(i,m){
        int s,c;
        cin >> s >> c;
        if(ans[s]==-1) ans[s] = c;
        else{
            if(ans[s] == c) continue;
            else fl = false;
        }
    }
    if(n>=2&&ans[1]==0) fl = false;
    if(n>=2&&ans[1]==-1) ans[1]=1; 
    if(fl){
        REP(i,n){
            if(ans[i]==-1) cout << 0;
            else cout << ans[i];
        }
        cout << endl;
    }else{
        cout << "-1" << endl;
    }
}