#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define pb push_back
const int maxn = 10000;
const int INF32 = 1'050'000'000;
const long long INF64 = 4'000'000'000'000'000'000;
const int MOD7 = 1'000'000'007;
const int MOD9 = 1'000'000'009;
const int mod = MOD7;

void ERROR(int num) { cout << "ERROR" << num << endl; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int dx[8]={-1,0,1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,1,-1};

vector<vector<char>> G;
vector<vector<int>> L;
vector<vector<int>> R;
vector<vector<int>> U;
vector<vector<int>> D;

int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);

    int H, W;
    cin >> H >> W;
    G.resize(H);
    rep(i,H) G[i].resize(W);
    rep(i,H)rep(j,W) cin >> G[i][j];

    L.resize(H);
    rep(i,H) L[i].resize(W);
    R.resize(H);
    rep(i,H) R[i].resize(W);
    U.resize(H);
    rep(i,H) U[i].resize(W);
    D.resize(H);
    rep(i,H) D[i].resize(W);
    //L
    rep(i,H){
      int cnt = 0;
      rep(j,W){
        if(G[i][j]=='.') cnt++;
        else cnt=0;
        L[i][j]=cnt;
      }
    }
    //R
    rep(i,H){
      int cnt = 0;
      for(int j = W-1; j>=0; j--){
        if(G[i][j]=='.') cnt++;
        else cnt=0;
        R[i][j]=cnt;
      }
    }
    //U
    rep(j,W){
      int cnt = 0;
      rep(i,H){
        if(G[i][j]=='.') cnt++;
        else cnt=0;
        U[i][j]=cnt;
      }
    }
    //D
    rep(j,W){
      int cnt = 0;
      for(int i = H-1; i>=0; i--){
        if(G[i][j]=='.') cnt++;
        else cnt=0;
        D[i][j]=cnt;
      }
    }

    //ans
    int ans = 0;
    rep(i,H) rep(j,W){
      int total = 0;
      if(G[i][j] =='.'){
        total = L[i][j]+R[i][j]+U[i][j]+D[i][j]-3;
        //printf("(%d,%d), L:%d R:%d U:%d D:%d\n", i,j,L[i][j], R[i][j],U[i][j], D[i][j]);
        ans = max(ans,total);
      }
    }
    cout << ans << endl;

} 