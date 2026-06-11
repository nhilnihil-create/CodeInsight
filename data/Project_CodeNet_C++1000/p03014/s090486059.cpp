#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int H,W; 

int Dfs(vector<vector<char>> M,int x,int y,int dx,int dy){
    if(x+dx<0 || x+dx>=H || y+dy<0 || y+dy>=W) return 0;
    if(M.at(x+dx).at(y+dy)=='#') return 0;
    return Dfs(M,x+dx,y+dy,dx,dy)+1;
}

int main(){
    cin>>H>>W;
    vector<vector<char>> M(H,vector<char>(W));
    rep(h,0,H)rep(w,0,W) cin>>M.at(h).at(w);

    vector<vector<int>> nW(H,vector<int>(W,0)),nH(H,vector<int>(W));
    rep(h,0,H){
        rep(w,0,W){
            if(M.at(h).at(w)=='.'){
                if(w==0) nW.at(h).at(w)=1;
                else nW.at(h).at(w)=nW.at(h).at(w-1)+1;
            }else nW.at(h).at(w)=0;
        }
    }
    rep(h,0,H){
        int v=0;
        _rep(w,W-1,0){
            if(nW.at(h).at(w)){
                if(v==0) v=nW.at(h).at(w);
                else nW.at(h).at(w)=v;
            }else v=0;
        }
    }

    rep(w,0,W){
        rep(h,0,H){
            if(M.at(h).at(w)=='.'){
                if(h==0) nH.at(h).at(w)=1;
                else nH.at(h).at(w)=nH.at(h-1).at(w)+1;
            }else nH.at(h).at(w)=0;
        }
    }
    rep(w,0,W){
        int v=0;
        _rep(h,H-1,0){
            if(nH.at(h).at(w)){
                if(v==0) v=nH.at(h).at(w);
                else nH.at(h).at(w)=v;
            }else v=0;
        }
    }

    int ans=0;
    rep(h,0,H){
        rep(w,0,W){
            if(M.at(h).at(w)=='#') continue;

            ans=max(ans,nW.at(h).at(w)+nH.at(h).at(w)-1);
        }
    }

    cout<<ans<<endl;
}