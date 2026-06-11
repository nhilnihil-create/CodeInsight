#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
 int n,m,x;
  cin>>n>>m>>x;
  ll c[n];
  ll a[n][m];
  ll ans=10000000;
  rep(i,n){
  cin>>c[i];//i;参考書 各々の金額を格納
    rep(j,m){
    cin>>a[i][j];
    }
  }
 /* rep(i,n){
    cin>>c[i];
  }
  rep(i,n) rep(j,m){
    cin>>a[i][j];
    }*/
  
 // int und[m];//各々のアルゴリズムの理解度をカウント
  int mon;//金額をカウント
  rep(mi,1<<n){
     mon=0;//金額カウントを初期化
    int und[m]={0};//理解度を初期化
   rep(i,n){//ある参考書パターンに対し
    
    if(mi>>i&1){//i番目は買ってる
    rep(j,m){
    und[j]+=a[i][j];//i番目の参考書に対する各々の理解度を足す
    }
      mon+=c[i];
      
    }
   //  cout<<mon<<endl;
    //買ってなかったら足さない
  }
    //理解度が超えているか判定
    int jud=0;
    rep(j,m){
    if(und[j]>=x){
    ++jud;
    }
   // cout<<und[j]<<endl;
    }
  //cout<<jud<<endl;
    if(jud==m){//全部習得できていたら 金額を更新するかも？
    if(ans>=mon){
      ans=mon;
      
    }
    }
    //cout<<ans<<endl;
  //  cout<<mon<<endl;
  }
  if(ans==10000000){
  cout<<"-1"<<endl;
  }
  else{
  cout<<ans<<endl;
  }
}
  