#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){
  int m,d; cin >> m >> d;
  
  int cnt = 0;
  
  for(int i = 1; i <= m; i++){
    
    int d1,d10;
    
    for(int j = 1; j <= d; j++){
      d10 = j/10;
      d1 = j%10;
    
    
    if( d1 >= 2 && d10 >= 2 && d1*d10 == i){ cnt++; }
    }
  }
  cout << cnt << endl;
  
  return 0;
}