#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){

  int X, N;  cin >> X >> N;
  vector<int> a(N);
  bool ok;
  int minCount=101;
  int ans=101;
  
  for(int i=0; i<N; i++){
    cin>>a.at(i);
  }
  

  for(int i=0; i<=101; i++){
    ok=true;
    for(int j=0; j<N; j++){
      if(i==a.at(j)){
        ok=false;
      }
    }
    if(ok){
      int count = abs(X-i);
      if(count<minCount){
        minCount=count;
        ans = i;
        //cout<<ans<<endl;
      }else if(count==minCount){
        ans = min(ans,i);
        //cout<<count<<endl;
      }
    }
  }
  cout << ans;
}