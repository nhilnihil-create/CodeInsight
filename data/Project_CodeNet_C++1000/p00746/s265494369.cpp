#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,a) for(int i=0;i<(a);i++)
#define MOD 1000000007

int main(){
  while(1){
    int n; cin>>n;
    if(n==0) break;
    int width[n]={}, height[n]={};
    int maw=0,miw=0,mah=0,mih=0;
    rep(i,n-1){
      int x,y;
      cin>>x>>y;
      if(y==0||y==2){
        width[i+1]=width[x]+(y==2?1:-1);
        miw=min(miw,width[i+1]);
        maw=max(maw,width[i+1]);
        height[i+1]=height[x];
      }else{
        height[i+1]=height[x]+(y==3?1:-1);
        mih=min(mih,height[i+1]);
        mah=max(mah,height[i+1]);
        width[i+1]=width[x];
      }
    }
    cout<<abs(maw-miw)+1<<" "<<abs(mah-mih)+1<<endl;
  }
  return 0;
}

