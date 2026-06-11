#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int, int> a;
  for(int i = 0; i < n; i++){
    int now;
    cin >> now;
    a[now]++;
  }
  
  bool ok = true;
  if(a.size() > 3) ok = false;
  if(a.size() == 1){
    if(!a.count(0)) ok = false;
  }
  if(a.size() == 2){
    if(!a.count(0)) ok = false;
    else{
      if(a.at(0) == n / 3 && n % 3 == 0) ok = true;
      else ok = false;
    }
  }
  if(a.size() == 3){
    queue<int> k;
    for(auto now : a){
      if(now.second != n/3) ok = false;
      if(n%3 != 0) ok = false;
      k.push(now.first);
    }
    int x, y, z;
    x = k.front();
    k.pop();
    y = k.front();
    k.pop();
    z = k.front();
    k.pop();
    int ans = x ^ y ^ z;
    if(ans != 0) ok = false;
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}