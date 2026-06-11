#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  rep(i,h){
    rep(j,w){
      if(i<=h-b-1&&j<=w-a-1||i>h-b-1&&j>w-a-1) cout<<0;
      else cout<<1;
    }
    cout<<endl;
  }
  return 0;
}