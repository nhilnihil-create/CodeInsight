#include <bits/stdc++.h>
using namespace std;
 
const long long mod=1e9+7;

int main(){
  int n,m;
  cin >> n >> m;
  vector<bool>ok(n+1,true);
  for(int i=0;i<m;i++){
    int a;
    cin >> a;
    ok.at(a)=false;
  }
  vector<long long>dp(n+1);
  dp.at(0)=1;
  for(int i=0;i<n;i++){
    for(int next=i+1;next<=min(n,i+2);next++){
      if(ok.at(next)){
        dp.at(next)+=dp.at(i);
        dp.at(next)%=mod;
      }
    }
  }
  cout << dp.at(n) << endl;
}
        
      