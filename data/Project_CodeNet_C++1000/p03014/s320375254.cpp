#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>>s(h+1,vector<char>(w+1));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++) cin >> s[i][j];
    s[i][w]='#';
  }
  for(int i=0; i<w+1; i++) s[h][i]='#';
  
  vector<vector<ll>>r(h,vector<ll>(w));
  vector<vector<ll>>l(h,vector<ll>(w));
  
  ll count=0;
  for(int i=0; i<h+1; i++){
   for(int j=0; j<w+1; j++){
     if(s[i][j]=='#'){
      for(int k=count; k>=1; k--){
        l[i][j-k]=count;
      }
       count=0;
       continue;
     }
     count++;
   }
  }
  
  count=0;
  for(int i=0; i<w+1; i++){
   for(int j=0; j<h+1; j++){
     if(s[j][i]=='#'){
      for(int k=count; k>=1; k--){
        r[j-k][i]=count;
      }
       count=0;
       continue;
     }
     count++;
   }
  }
  
  ll ans=0;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      ll x = r[i][j]+l[i][j]-1;
      ans=max(ans,x);
    }
  }
  
  cout << ans << endl;
  
}