#define _GLIBCXX_DEBUG 
#include <bits/stdc++.h>
using namespace std;

int main () {
  int n;
  cin >> n;
  
  int a;
  map<int,int> m;
  for(int i=0; i<n-1; i++) {
    cin >> a;
    m[a]++;
  } 
  
  for(int i=1; i<=n; i++) {
    if(m.count(i)) cout << m[i] << endl;
    else cout << 0 << endl;
  }
  
  return 0;
}