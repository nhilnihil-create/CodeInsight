#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long int A,B,V,W,T,t,l,l2;
  cin >> A >> V;
  cin >> B >> W;
  cin >> T;
  if(V>W){
    l=A-B;
    if(l<0){
      l *= -1;
    }
    l2 = T*(V-W);
    if(l<=l2){
      cout << "YES" << endl;
    }
    else{
    cout << "NO" << endl;
    }
  }
  else{
    cout << "NO" << endl;
  }
}