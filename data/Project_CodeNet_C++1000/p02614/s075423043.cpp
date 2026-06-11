#include <bits/stdc++.h>
using namespace std;

int ans;

signed main(){
  int h,w,K;cin>>h>>w>>K;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin>>s[i];
  for(int i=0;i<(1<<h);i++){
    for(int j=0;j<(1<<w);j++){
      int tmp=0;
      for(int k=0;k<h;k++){
        for(int l=0;l<w;l++){
          if(((i>>k)&1)&&((j>>l)&1)&&s[k][l]=='#')tmp++;
        }
      }
      ans+=tmp==K;
    }
  }
  cout<<ans<<endl;
}
