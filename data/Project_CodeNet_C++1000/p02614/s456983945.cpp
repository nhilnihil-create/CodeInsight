#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
int main(){
  int h,w,k;
  cin>>h>>w>>k;
  char c[h][w];
rep(i,h) rep(j,w) {cin>>c[i][j];}
  
  long long count=0; //条件を満たすパターンをカウント
  rep(mi,1<<h)rep(mj,1<<w){//1<<3(=3桁シフト1000) repの場合000~111(1000-1)を表す
  int black=0;
    rep(i,h)rep(j,w){
      if((mi>>i)&1){continue;}//mi(行)のi桁目が1⇒その行は全部消滅
       if((mj>>j)&1){continue;}//mj(列)のj桁目が1⇒その列は全部消滅
      if(c[i][j]=='#'){black++;}//行も列も消えてないマスが黒⇒blackをカウント
    }
    if(black==k){//条件を満たす場合
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}