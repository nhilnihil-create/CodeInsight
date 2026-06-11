#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n,x,y;
  cin>>n>>x>>y;
  x--; y--;
  vector<int> ans(n,0);
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      ans[min(j-i,abs(i-x)+abs(j-y)+1)]++;
    }
  }
  rep(i,n-1){
    cout<<ans[i+1]<<endl;
  }
}
