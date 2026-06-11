#include <bits/stdc++.h>
using namespace std;


int main(){
  long long n,k;
  cin >> n >> k;
  vector<long long> a(n+1);
  for(int i = 1;i < n+1;i ++){
    cin >> a.at(i);
  }
  
  long long x = 0;
  long long now = 1;
  vector<int> check(n+1,0);
  check.at(1) = 1;
  while(1){
   // cout << a.at(now) << check.at(a.at(now)) << endl;
    
    x++;
    if(check.at(a.at(now)) != 1){
      check.at(a.at(now)) = 1;
      now = a.at(now);
    }
    else{
      break;
    }
  }
  now = a.at(now);
  //cout << "now:" << now << endl;
  //cout << "x:" << x << endl;
  long long p = now;
  long long y = 1;
  
  while(a.at(now) != p){
   // cout << "here" << endl;
    y++;
    now = a.at(now);
  }
  //cout << "y:" << y << endl;
  long long z = 0;
  long long ans = 1;
  if(k > x){  
    z = (k - x) % y;
    ans = p;
    for(int i = 0;i < z;i++){
      ans = a.at(ans);
    }
  }
  else{
    z = k;
    for(int i = 0;i < z;i++){
      ans = a.at(ans);
    }
  }
  cout << ans  << endl;
}



