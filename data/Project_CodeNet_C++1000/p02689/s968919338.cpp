#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int obs,rd;
  cin >> obs >> rd;
 // vector<long long> hgt(obs);
  map<int,long long> o_h;
  map<int,int> res;
  map<int,bool> mp;
  int a,b;
  
  for(int i = 0; i < obs; i++){
    long long x;
    cin >> x;
  //  hgt[i] = x;
    o_h[i+1] = x;
  }
 // cout << res[1];
  
  for(int i = 0; i < rd; i++){
    cin >> a >> b;
    if(o_h[a] <= o_h[b]){
      res[a] = -1;
    }
    if(o_h[b] <= o_h[a])res[b] = -1;
  //  mp[a] = mp[b] = true;
  }
  int cnt = 0;
  for(int i = 1; i <= obs; i++){
    if(res[i] != -1)cnt++;
  }
  cout << cnt;
  
}