#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  vector<vector<ll>> num(10, vector<ll>(10, 0));
  
  
  for(int i=1; i<=n; i++){
    vector<int> d;
    int nn = i;
    while(nn){
      d.push_back(nn%10);
      nn /= 10;
    }
    
    int a = d[0];
    int b = d.back();
    if(!a || !b) continue;
    
    num[a][b]++;
  }
  
  ll  res = 0;
  for(int a=1; a<10; a++){
    for(int b=1; b<10; b++){
      res += num[a][b]*num[b][a];
    }
  }
  
  
  cout << res << endl;
  
  return 0;
}