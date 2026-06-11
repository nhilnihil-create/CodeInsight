#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  if(n % 2){
    for(int i = 1; i <= m; i++) cout << i << ' ' << n-i << endl;
  }
  else{
    for(int i = 1; i <= m; i++){
      if(i < (double)n/4) cout << i << ' ' << n-i << endl;
      else cout << i << ' ' << n-i-1 << endl;
    }
  }
}