#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
 int n,m;
  cin>>n>>m;
  int h[n];
  int a[m],b[m];//道mが結ぶ展望台
 
  //展望台iから一本の道を使ってたどりつける展望台の標高の最大値　よりも展望台iの標高が高いことを示す。
  int d[n]={0};//展望台が良い展望台かどうか？
  rep(i,n){
  cin>>h[i];//各展望台の高さ
  }
  rep(i,m){
  cin>>a[i]>>b[i];//道mはどこ(何番目の展望台)とどこを結んでるの?
    if(h[a[i]-1]>h[b[i]-1]){
    d[b[i]-1]=1;//b[i]番目の展望台は良い展望台ではない
    }
    else if(h[b[i]-1]>h[a[i]-1]){
    d[a[i]-1]=1;//a[i]番目の展望台は良い展望台ではない
    }
    else//両方同じ高さ
    {
      d[b[i]-1]=1;
      d[a[i]-1]=1;
    }
     
  }
int cnt=0;
  rep(i,n){
 //   cout<<d[i]<<endl;
  if(d[i]==0){
  cnt++;
  }
  }
  cout<<cnt<<endl;
                 }