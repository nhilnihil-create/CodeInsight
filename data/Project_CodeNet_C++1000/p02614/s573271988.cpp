#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k;
  cin>>h>>w>>k;
  char s[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>s[i][j];
    }
  }
  long long ans=0;
  for(int bit1=0;bit1<(1<<h);bit1++){
    for(int bit2=0;bit2<(1<<w);bit2++){
      long long black=0;
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          if(bit1&(1<<i)) continue;
          if(bit2&(1<<j)) continue;
          if(s[i][j]=='#') black++;
        }
      }
      if(black==k) ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
