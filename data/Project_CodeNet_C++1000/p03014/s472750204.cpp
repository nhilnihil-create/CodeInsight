#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S.at(i);
    vector<vector<int>> obyoko(H,vector<int>(1,-1)),obtate(W,vector<int>(1,-1));
    rep(i,H){
        rep(j,W){
            if(S.at(i).at(j)=='#'){
                obyoko.at(i).pb(j);
                obtate.at(j).pb(i);
            }
        }
    }
    rep(i,H){obyoko.at(i).pb(W);}
    rep(i,W){obtate.at(i).pb(H);}
    int ans=1;
    rep(i,H){
        rep(j,W){
            if(S.at(i).at(j)=='#')continue;
            auto y=lower_bound(obyoko.at(i).begin(),obyoko.at(i).end(),j);
            int before,after;
            after=*y;
            y--;
            before=*y;
            int now=after-before-1;
            auto t=lower_bound(obtate.at(j).begin(),obtate.at(j).end(),i);
            after=*t;
            t--;
            before=*t;
            now+=after-before-2;
            chmax(ans,now);
        }
    }
    cout<<ans<<endl;
}