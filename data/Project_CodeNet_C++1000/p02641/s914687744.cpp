#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,n;
  cin >> x >> n;
  if (n == 0) {
    cout << x << endl;
    return 0;
  }
  vector<int> p(n);
  for(auto &a: p) cin >> a;
  for(int i=0; i<=n; i++){
    if(std::find(p.begin(), p.end(), x-i) == p.end()){
      cout << x - i << endl;
      break;
    }
    if(std::find(p.begin(), p.end(), x+i) == p.end()){
      cout << x + i << endl;
      break;
    }
  }
}