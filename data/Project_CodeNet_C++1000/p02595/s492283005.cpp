#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int  n;
  long d;
  cin >> n >> d;
  long dd = d*d;
  int total = 0;
  
  for (int i = 0; i < n; i++){
    
    long x, y;
    cin >> x >> y;
    
    long aa = (x*x) + (y*y);
    if(aa <= dd){
      total += 1;
    }
    
  }
  
  cout << total << endl;

  
}