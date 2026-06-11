#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x,t;
  cin >> n >> x >> t;
  
  int tak = 0;
  
  for(int i=1;i<=1000000;i++){
    tak = x*i;
    if(tak>=n){
      cout << t*i << endl;
      return 0;
    }
  }
}