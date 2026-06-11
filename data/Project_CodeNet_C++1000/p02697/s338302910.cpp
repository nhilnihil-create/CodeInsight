#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(void){ 
  
  int n,m; cin >> n >> m;
  
  bool flag = true;
  
  if( n % 2 == 1 ) { 
    int cnt = 0;
    for(int a = 1,b = n; a < b; a++, b--){ 
      cout << a << " " << b << endl;
      cnt++;
      if( cnt >= m ){ break;}
    }
  } 
  else{ 
    int cnt = 0;
    for(int a = 1, b = n; a < b; a++, b--){ 
      if( b-a <= n/2 && flag){ a++; flag = false;}
      cout << a << " " << b << endl;
      cnt++;
      if( cnt >= m ){ break;}
      
    }
      
    return 0;
  }
  
  
}