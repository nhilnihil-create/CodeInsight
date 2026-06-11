#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  int ans[1010][1010];
  rep(i,h){
    rep(j,w){
      if(i<b){
        if(j<a) cout<<0;
        else cout<<1;
      }else{
        if(j<a) cout<<1;
        else cout<<0;
      }
    }
    cout<<endl;
  }
}