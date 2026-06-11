#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int H,W; cin>>H>>W;
    vector<vector<bool>> Grid(H+1,vector<bool>(W+1,true));
    rep(h,1,H+1)rep(w,1,W+1){
        char c; cin>>c;
        if(c=='#') Grid.at(h).at(w)=false;
    }

    vector<vector<int>> Dp(H+1,vector<int>(W+1,100000));
    Dp.at(0).at(1)=Dp.at(1).at(0)=0;
    rep(h,1,H+1){
        rep(w,1,W+1){
            Dp.at(h).at(w)=min(Dp.at(h-1).at(w)+(Grid.at(h-1).at(w) && !Grid.at(h).at(w)),Dp.at(h).at(w-1)+(Grid.at(h).at(w-1) && !Grid.at(h).at(w)));
        }
    }

    cout<<Dp.at(H).at(W)<<endl;
}