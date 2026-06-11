#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

#define MAX 2020

char g[MAX][MAX];

int main(){
  int H,W;cin>>H>>W;
  vector<vector<int>> row(H),col(W);
  rep(i,H){row[i].push_back(0);row[i].push_back(W+1);}
  rep(j,W){col[j].push_back(0);col[j].push_back(H+1);}
  rep(i,H){
    string s;cin>>s;
    rep(j,W){
      g[i][j]=s[j];
      if(s[j]=='#'){row[i].push_back(j+1);col[j].push_back(i+1);}
    }
  }
  rep(i,H) sort(all(row[i]));
  rep(j,W) sort(all(col[j]));
  //rep(i,H){rep(j,row[i].size()){cout<<row[i][j];}cout<<endl;}
  int ans=0;
  rep(i,H){
    rep(j,W){
      if(g[i][j]=='#')continue;
      int r = lower_bound(all(row[i]),j+1)-row[i].begin();
      int c = lower_bound(all(col[j]),i+1)-col[j].begin();
      ans = max(ans,row[i][r]-row[i][r-1]-1 + col[j][c]-col[j][c-1]-1 - 1);
      //cout << "i,j" << i << j << "rc" << row[i][r]-row[i][r-1]-1 << col[j][c]-col[j][c-1]-1 << endl;
    }
  }
  cout<<ans<<endl;
}