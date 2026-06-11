#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int n, m;
  cin >> n >> m;
  
  int total = 0;
  for(int i = 1; i <= m; i++){
    int a;
    cin >> a;
    total += a;
  }
  
  if(n >= total) cout << n - total << endl;
  else cout << -1 << endl;
} 