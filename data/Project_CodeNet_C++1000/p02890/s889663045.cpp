//プライオリティーキュー
#include "bits/stdc++.h"
#include <queue>
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007
using vi = vector<ll>; // intの1次元の型に vi という別名をつける
using vvi = vector<vi>; // intの2次元の型に vvi という別名をつける



int main()
{
  int n;
  int b;
  cin>>n;
  vector<int> xnum(n);//xnum(x)は縦になんこあるか
  vector<int> ynum(n);//ynum(y)は横になんこあるか

  REP(i,n){
    cin>>b;
    b--;
    xnum[b]++;//iカードが何枚あるか
  }
  sort(xnum.begin(), xnum.end(),greater<int>());

  int t=xnum[0];
  REP(i,n){
    if (xnum[i]<t){
      for(int j=xnum[i];j<t;j++){
        ynum[j]=i;
      }
      t=xnum[i];
    }
  }
  
  if (0<t){
    for(int j=0;j<t;j++){
      ynum[j]=n;
    }
  }


  vector<int> ans(n);
  int leftuse=0;//穴埋めに自由に使える面積
  int h=0;//答えとなる高さ
  int s=0;//顕さんに使う面積
  for (int i = n-1; i >=0; i--)
  {
    for(;;){
      if (h==n){
        break;
      }

      if ( (i+1)*h <= s+leftuse ){
        s+=min(ynum[h],i+1);
        h++;
      }else{
        break;
      }
    }

    ans[i]=h-1;

    s-=min(xnum[i],h);
    leftuse+=xnum[i];
  }
  ans[0]=n;
  REP(i,n){
    cout<<ans[i]<<endl;
  }
  return 0;
}
