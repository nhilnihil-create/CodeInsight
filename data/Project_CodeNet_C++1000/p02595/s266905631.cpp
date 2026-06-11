#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  
  int x, y;
  int cnt=0;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    if(sqrt((long long)x*x+(long long)y*y) <= d)
      cnt++;    
  }
  
  cout << cnt << endl;
}
