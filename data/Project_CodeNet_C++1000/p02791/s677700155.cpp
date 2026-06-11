#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >> n;
  
  vector<ll> p(n);
  for(int i=0; i<n; i++) cin >> p[i];
  
  vector<ll> res;
  res.push_back(p[0]);
  ll index = 0;
  for(int i=1; i<n; i++){
    if(res[index]>p[i]){
      res.push_back(p[i]);
      index++;
    }
  }
  
  cout << index+1 << endl;
  
  return 0;
}