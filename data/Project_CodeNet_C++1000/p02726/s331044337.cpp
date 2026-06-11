#include <bits/stdc++.h>  
using namespace std;
#define rep(i,k,n) for(int i=(int)(k); i<(int)(n); i++)

int main() {
  int n,x,y; cin>>n>>x>>y;
  x--;y--;
  vector<int> v(n-1,0);
  rep(i,0,n-1){
    rep(j,i+1,n){
      int k=j-i-1;
      if(i<=x && y<=j){
        k+=x-y+1;      
      }
      k=min(k,abs(x-i)+abs(y-j));
      v[k]++;
    }
  }
  rep(i,0,n-1){cout<<v[i]<<endl;}
}