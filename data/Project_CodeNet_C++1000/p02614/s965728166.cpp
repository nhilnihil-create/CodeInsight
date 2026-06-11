#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w,g; cin>>h>>w>>g;
  string arr[h];
  for(int i=0;i<h;i++) cin>>arr[i]; 
  int tb=0;
  for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(arr[i][j]=='#') tb++; 
  int dp1[h],dp2[w],res=0;
  for(int i=0;i<h;i++){int cnt=0; for(int j=0;j<w;j++) if(arr[i][j]=='#') cnt++; dp1[i]=cnt;  }
  for(int i=0;i<w;i++){int cnt=0; for(int j=0;j<h;j++) if(arr[j][i]=='#') cnt++; dp2[i]=cnt; }
  for(int i=0;i<(1<<h);i++){
    int ans=tb;
    //cout<<ans<<endl;
    for(int j=0;j<h;j++)
      if(i&(1<<j)) ans-=dp1[j];
    for(int k=0;k<(1<<w);k++){
      int tmp=ans;
      for(int m=0;m<w;m++) 
        if(k&(1<<m)) tmp-=dp2[m]; 
      for(int p=0;p<h;p++)
        for(int q=0;q<w;q++)
          if((i&(1<<p))&&(k&(1<<q))&&arr[p][q]=='#') tmp++;
       if(tmp==g) res++;
    }
    }
         cout<<res<<endl;
    }