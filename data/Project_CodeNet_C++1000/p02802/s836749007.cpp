#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,m,p;
  string s;
  cin >> n >> m;
  
  vector<int> a(n+1,0),w(n+1,0);
  
  int Asum = 0,Wsum = 0;
  
  for ( int i = 0; i < m; i++){
    cin >> p >> s;
    if ( a[p] == 0 && s == "AC" ){
      a[p] = 1;
      Asum++;
    }else if ( a[p] == 0 && s == "WA" ){
      w[p]++;
    }
  }
  
  for ( int i = 1; i <= n; i++){
    if ( a[i] == 1 ){
      Wsum += w[i];
    }
  }
  
  cout << Asum << ' ' << Wsum << endl;  
  
}