#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long m,dsum=0,csum=0;
  cin >> m;
  vector<long> d(m),c(m);
  for(long i=0;i<m;i++) {
    cin >> d[i] >> c[i];
    csum+=c[i];
    dsum+=d[i]*c[i];
  }
  cout << csum-1+(dsum-1)/9 << endl;
}