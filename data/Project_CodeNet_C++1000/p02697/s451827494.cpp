#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(void){ 
  int n,m; cin >> n >> m;
  int cnt = 0;
  if(n%2){ 
    for(int l = 1,r = n-1; l < r ; l++,r--){ 
      cout << l << " " << r << endl;
      cnt++;
      if( cnt >= m ){ break;}
    }
  }
    else{ 
      bool flag = false;
      for(int l = 1,r = n-1; l < r; l++,r--){
        if( !flag && r-l <= n/2 ){ r--; flag = true;}
        cout << l << " " << r << endl;
        cnt++;
        if(cnt >= m ){ break;
                     }
      }
    }

  return 0;
}