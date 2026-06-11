#include <bits/stdc++.h>
using namespace std;

int main() {
  long long m,d; cin >> m >> d;
  long long ans;
  for(int j = 1; j<=m; j++){
    for(int i = 1; i<=d; i++){
      long long a = i/10;
      long long b = i%10;
      if(a>=2&&b>=2&&a*b==j) ans++;
    }
  }
  cout << ans << endl;
  
}