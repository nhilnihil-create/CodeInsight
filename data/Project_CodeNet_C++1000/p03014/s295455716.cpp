#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int hor[2100][2100];


int main() {
  int H, W;
  cin >> H>>W;
  vector<string> field(H);
  for(int i = 0; i < H; i++) {
    cin>>field[i];
  }
  int ans=0;
  bool M = false;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(field[i][j]=='#') continue;
      int cnt = 0;
      int k = 0;
      if(j==0||field[i][j-1]=='#'){
        while(j+k<W){
          if(field[i][j+k]=='.') hor[i][j]++;
          if(field[i][j+k]=='#') break;
          k++;
        }
        k=0;
        while(j+k>=0){
          if(field[i][j+k]=='.') hor[i][j]++;
          if(field[i][j+k]=='#') break;
          k--;
        }
      }
      else hor[i][j] = hor[i][j-1];
      k=0;
      while(i+k<H){
        if(field[i+k][j]=='.') cnt++;
        if(field[i+k][j]=='#') break;
        k++;
      }
      k=0;
      while(i+k>=0){
        if(field[i+k][j]=='.') cnt++;
        if(field[i+k][j]=='#') break;
        k--;
      }
      cnt+=hor[i][j];
      cnt-=3;
      chmax(ans,cnt);
      if (ans == H+W-1){
        M = true;
        break;
      }
    }
    if(M) break;
  }
  cout<<ans<<endl;
}