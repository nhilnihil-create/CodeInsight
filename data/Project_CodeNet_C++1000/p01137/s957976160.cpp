#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int LLINF = 1LL << 60;

signed main()
{
  
  int Z[105], Y[1005];
  
  for(int i = 0; i <= 1000; i++) {
    if(i * i <= 1000000) {
      Y[i] = i * i;
    }
    if(i * i * i <= 1000000) {
      Z[i] = i * i * i;
    }
  }
  
  int E;
  while(cin >> E, E) {
    
    int minv = LLINF;
    
    for(int i = 0; i <= 100; i++) {
      for(int j = 0; j <= 1000; j++) {
	if(Z[i] + Y[j] <= E) {
	  minv = min(i + j + E - (Z[i] + Y[j]), minv);
	}
      }
    }
    
    cout << minv << endl;

  }
  
  return 0;
}