#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)n; i++)

int main(){
  int H,W,K;cin>>H>>W>>K;
  vector<string> c(H);
  rep(i,H)cin>>c[i];
  int ans=0;

  for(int i=0; i<(1<<H); i++){
    for(int j=0; j<(1<<W); j++){
      
      int cnt = 0;
      for(int h=0; h<H; h++){
        for(int w=0; w<W; w++){
          if(i&(1<<h) || j&(1<<w))continue;
          if(c[h][w]=='#')cnt++;
        }
      }

      if(cnt==K)ans++;
    }
  }

  cout<<ans<<endl;
}