#include<bits/stdc++.h>
using namespace std;

int main(){
  int p, q, r;
  cin >> p >> q >> r;
  
  if(min({p, q, r}) == q){
    cout << min(p, q) + min(p, r) << endl;
  } else{
    cout << min(p, q) + min(q, r) << endl;
  }
  return 0;
}