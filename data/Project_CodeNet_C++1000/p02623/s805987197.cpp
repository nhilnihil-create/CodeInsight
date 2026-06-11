#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
int n,m,k;
 cin>>n>>m>>k;
  long long t=0;
  int a[n],b[m];
  rep(i,n){
  cin>>a[i];
    
  }
rep(i,m){
cin>>b[i];
t+=b[i];//tにbを全部入れる
}
  int j=m;
  int ans =0;//カウント用
  rep(i,n+1){//a[n-1](最期の配列)を+した後の結果はn番目のループに反映される
  while(j>0&&t>k){//制限時間kを超えているとき、jをmから-していく演算(jが負にならない範囲で)
   --j;//前置インクリメント⇒初めにjをマイナスしてから、b[j]を引く　ここで-1になるとだめなので、while文はj>0となっている。
    t-=b[j];
   
  // cout<<j<<endl;
  }
    //cout<<j<<endl;
    if(t>k)break;//a[i]を足していった結果、b[j]をいくら減らしてもkをどうしても超えてしまう場合、breakする
    //cout<<i+j<<endl;
    ans=max(ans,i+j);//過去のansとi+jのうち大きい方をansに代入する
    if(i==n) break;//n番目の最終ループの時、終了する
  t+=a[i];//a[i]を足す
    //cout<<ans<<endl;
  }
  cout<<ans<<endl;
  return 0;
}