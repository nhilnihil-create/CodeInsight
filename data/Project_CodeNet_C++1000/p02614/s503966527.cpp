#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,k;
  cin>>h>>w>>k;
  string c[h];
  int ans=0;
  for(int i=0;i<h;i++)
    cin>>c[i];
  for(int i=0;i<((1<<h)-1);i++)
    for(int j=0;j<((1<<w)-1);j++){
      int blackn=0;
      for(int p=0;p<h;p++)
        for(int l=0;l<w;l++)
          if(((i>>p)&1)==0&&((j>>l)&1)==0&&c[p][l]=='#') blackn++;
      if(blackn==k)
        ans++;
    }
  cout<<ans<<endl;
  return 0;
}