#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
  int n,k,count=0;
  cin >> n >> k;
  vector<int> d(k),check(n+10,0);
  
  rep(i,k){
    cin >> d.at(i);
    vector<vector<int>> a(k, vector<int>(d.at(i)));
    rep(j,d.at(i)){
      cin >> a.at(i).at(j);
      check.at(a.at(i).at(j))++;
    }
  }

  for(int i=1; i<=n; i++){
    if(check.at(i) == 0){
      count++;
    }
  }
  cout << count << endl;
  
  return 0;
}
