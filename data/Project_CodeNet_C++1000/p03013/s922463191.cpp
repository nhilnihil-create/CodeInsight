#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nmax = 1000000007;

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll> dp(n+1,0);
  vector<int> a(m);
  for(int i=0;i<m;i++){
    cin >> a.at(i);
  }
  
  auto itr = find(a.begin(),a.end(),1);
  if(itr == a.end()){
    dp.at(1) = 1;
  }
  
  itr = find(a.begin(),a.end(),2);
  if(n>1){
    if(itr != a.end()){
      dp.at(2) = 0;
    }else{
      dp.at(2) = dp.at(1) + 1;
    }
  }
  
  for(int i=3;i<n+1;i++){
    itr = find(a.begin(),a.end(),i);
    if(itr == a.end()){
      dp.at(i) = (dp.at(i-1) + dp.at(i-2)) % nmax;
    }else{
      dp.at(i) = 0;
    }
  }
	
  cout << dp.at(n) << endl;
  return(0);
}