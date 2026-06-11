#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h,w;cin>>h>>w;
  string s[h];
  rep(i,h)cin>>s[i];
  vector<vi> hori(h, vi(w, 0)), vart(h, vi(w, 0));
  rep(i,h) {
    if (s[i][0]=='.') hori[i][0]=1;
    rep(j,w-1) {
      if (s[i][j+1]=='.') hori[i][j+1]=hori[i][j]+1;
      else {
        int k=j, x=hori[i][j];
        while (k>=0 && s[i][k]=='.') {
          hori[i][k]=x;
          k--;
        }
      }
    }
    if (s[i][w-1]=='.') {
      int k=w-1, x=hori[i][w-1];  
      while (s[i][k]=='.') {
        hori[i][k]=x;
        k--;
      }
    }
  }
  //rep(i,h) {rep(j,w)cout<<hori[i][j]<<" ";cout<<endl;}cout<<endl;
  
  rep(j,w) {
    if (s[0][j]=='.') vart[0][j]=1;
    rep(i,h-1) {
      if (s[i+1][j]=='.') vart[i+1][j]=vart[i][j]+1;
      else {
        int k=i, x=vart[i][j];
        while (k>=0 && s[k][j]=='.') {
          vart[k][j]=x;
          k--;
        }
      }
    }
    if (s[h-1][j]=='.') {
      int k=h-1, x=vart[h-1][j];  
      while (s[k][j]=='.') {
        vart[k][j]=x;
        k--;
      }
    }
  }
  //rep(i,h) {rep(j,w)cout<<vart[i][j]<<" ";cout<<endl;}
  
  int ans=0;
  rep(i,h)rep(j,w){
    ans = max(ans, hori[i][j]+vart[i][j]-1);
  }
  cout<<ans;
}
