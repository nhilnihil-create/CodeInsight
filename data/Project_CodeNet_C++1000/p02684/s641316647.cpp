#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,K;cin>>N>>K;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    A.at(i)--;
  }//　テレポーター指示
  int logK=1;
  while((1LL<<logK)<K) logK++;//2^logKがKを超えるまでlogKを増やす
  long DB[logK][N];//DB[i][j]をj番目のまちから2^i進んだ街にする
  for(int i=0;i<N;i++) DB[0][i]=A[i];//初期条件
  for(int i=0;i<logK-1;i++){
    for(int j=0;j<N;j++) DB[i+1][j]=DB[i][DB[i][j]];
  }//ここまで計算(下準備)
  
  int ans=0;
  for(int i=0;K>0;i++){
    if(K & 1) ans=DB[i][ans];
    K=K>>1;
  }
  cout<<ans+1<<endl;
}
