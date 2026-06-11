#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int m=0;
  for(int i=1;i<1001;i++){
    n-=100;
    if(n>=0 && n<=5*i){
      m=1;
      break;
    }
  }
  
  cout << m << endl;

}