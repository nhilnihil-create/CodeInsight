#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

// int left[2100][2100], right[2100][2100], up[2100][2100], down[2100][2100];

int main(){

    int h, w;
    cin>>h>>w;
    vector<string> S(h);
    rep(i,h) cin>>S[i];
    vector<vector<int>> left(h+1, vector<int>(w+1));
    vector<vector<int>> right(h+1, vector<int>(w+1));
    vector<vector<int>> up(h+1, vector<int>(w+1));
    vector<vector<int>> down(h+1, vector<int>(w+1));
    

    //前処理
    rep(i,h){
        int cnt = 0;
        rep(j,w){
            if(S[i][j]=='#') cnt = 0;
            else cnt++;
            left[i][j] = cnt;
        }
    }
    rep(i,h){
        int cnt=0;
        for(int j=w-1;j>=0;j--){
            if(S[i][j]=='#') cnt=0;
            else cnt++;
            right[i][j]=cnt;
        }
    }
    rep(j,w){
        int cnt=0;
        rep(i,h){
            if(S[i][j]=='#') cnt=0;
            else cnt++;
            up[i][j]=cnt;
        }
    }
    rep(j,w){
        int cnt=0;
        for(int i=h-1;i>=0;i--){
            if(S[i][j]=='#') cnt=0;
            else cnt++;
            down[i][j]=cnt;
        }
    }
    
    int ans=0;
    rep(i,h){
        rep(j,w){
            if(S[i][j]=='#') continue;
            ans = max(ans, left[i][j]+right[i][j]+up[i][j]+down[i][j]-3);
        }
    }
    cout<<ans<<endl;

    return 0;
}
