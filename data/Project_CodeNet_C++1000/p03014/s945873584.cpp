#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h,w;
    cin >> h >> w;
    vector<vector<int>> dp(w+5,vector<int>(h+5,0));
    vector<vector<int>> t(w),y(h);
    rep(i,h){
        int x=i;
        y[x].push_back(0);
    }
    rep(i,w){
        int z=i;
        t[z].push_back(0);
    }
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            if(s[j]=='.') continue;
            int x=i, z=j;
            t[z].push_back(x+1);
            y[x].push_back(z+1);
        }
    }
    rep(i,h){
        int x=i;
        y[x].push_back(w+1);
    }
    rep(i,w){
        int z=i;
        t[z].push_back(h+1);
    }
    rep(i,w){
        for(size_t j=1; j<t[i].size(); ++j){
            if((t[i][j-1]+1)==t[i][j]) continue;
            for(int k=t[i][j-1];k<t[i][j]-1;++k){
                dp[i][k]=t[i][j]-t[i][j-1]-1;
            }
        }
    }
    rep(i,h){
        for(size_t j=1; j<y[i].size(); ++j){
            if((y[i][j-1]+1)==y[i][j]) continue;
            for(int k=y[i][j-1];k<y[i][j]-1;++k){
                dp[k][i]+=y[i][j]-y[i][j-1]-2;
            }
        }
    }
    int ans=0;
    rep(i,h){
        rep(j,w){
            ans=max(ans,dp[j][i]);
        }
    }
    cout << ans << "\n";
    return 0;
}   