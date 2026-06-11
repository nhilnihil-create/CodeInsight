#include <iostream>
using namespace std;

int main(){
  int n; cin >> n;
  int w[n];
  for(int i=0; i<n; ++i) cin >> w[i];
  
  int s1 = 0, s2 = 0;
  for(int i=0; i<n; ++i) s2 += w[i];
  
  int ms = s2;
  for(int i=0; i<n; ++i){
    s1 += w[i];
    s2 -= w[i];
    if(ms > abs(s1 - s2)) ms = abs(s1 - s2);
  }
  
  cout << ms << endl;
  return 0;
}