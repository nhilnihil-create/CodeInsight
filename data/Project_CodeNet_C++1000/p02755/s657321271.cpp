#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int a, b;
  cin >> a >> b;
  
  bool ok = false;
  for(int i = 1; i < 5000; i++){
    int x = i*8/100;
    int y = i*10/100;
    if(x == a && y == b){
      ok = true;
      cout << i << endl;
      break;
    }
  }
  
  if(ok == false) cout << -1 << endl;
  return 0;
}