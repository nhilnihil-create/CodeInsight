#include <bits/stdc++.h>
using namespace std;

int main(){
  int k , x ;
  cin >> k >> x ;
  for(int i=1;i<k;i++){
    cout << x-k+i << endl;
  }
  cout << x << endl;
  for(int i=1;i<k;i++){
    cout << x + i << endl;
  }
  
}