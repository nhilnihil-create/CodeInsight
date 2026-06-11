#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W,K;cin>>H>>W>>K;
  char A[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cin>>A[i][j];
  }
  int ans=0;
  for(int s=0;s<(1<<H);s++){//sを2進表示した時の6桁数字を縦の選び方と考える
    for(int t=0;t<(1<<W);t++){//tは横
      int black=0;
      //以下、あるsとtに対してH*Wマスを探索
      //s,tのbitをi,jずらした(2でi,j回割った)ときちょうど1なら、そこは赤く塗られているので除外      
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if((s & 1<<i)==0 && (t & 1<<j)==0 && A[i][j]=='#') black++;
          //if((s>>i & 1)==0 && (t>>j & 1)==0 && A[i][j]=='#') black++;
          
        }
      }
      if(black==K) ans++;
    }
  }
  cout<<ans<<endl;
}