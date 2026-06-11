#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, n;
  cin >>  x >> n;
  
  vector<int> v(102);
  for(int i=0; i<=101; i++){
    v.at(i) = i;
  }
  
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    v.at(a) = -100;
  }
  
  vector<int> w;
  for(int i=0; i<102; i++){
    if(v.at(i) != -100)
      w.push_back(v.at(i));
  }
  
  int ans = x;
  for(int i=0; i<w.size(); i++){
    if(w.at(i) == x){
      break;
    }
    else if(w.at(i) > x){
      int prv = (i-1 < 0) ? 0 : i-1;
      int nxt = i;
      int prv_abs = x - w.at(prv);
      int nxt_abs = w.at(nxt) - x;
      
      if(prv_abs == nxt_abs || prv_abs < nxt_abs)
        ans = w.at(prv);
      else
        ans = w.at(nxt);
      break;
    }
  }

  cout << ans << endl;
}

  