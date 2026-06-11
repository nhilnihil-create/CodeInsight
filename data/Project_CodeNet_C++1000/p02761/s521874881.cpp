#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,M; cin>>N>>M;
    vector<int> ans(N,-1);

    bool flg = true;
    rep(i,M){
        int s,c; cin>>s>>c;
        s--;
        if(ans[s]==-1 || ans[s]==c){
            ans[s]=c;
        }else{
            flg = false;
        }
    }
    
    if(N>1){
        if(ans[0]==0) flg = false;
        if(ans[0]==-1) ans[0] = 1;
    }

    if(flg){
        for(int x:ans){
            if(x==-1) cout << 0;
            else cout << x;
        }    
        cout << endl;
    }else{
        cout << -1 << endl;
    }
}
