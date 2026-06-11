#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k,ans=0;
  cin >> h >> w >> k;
  string s[h];
  for(int i=0;i<h;i++)cin >> s[i];
  for(int mask=0;mask<(1<<h);mask++){
    for(int mask2=0;mask2<(1<<w);mask2++){
      int brack=0;
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
          if(mask&(1<<i) && mask2&(1<<j) && s[i][j]=='#')brack++;
        }
      }
      if(brack==k)ans++;
    }
  }
  cout << ans << endl;
}