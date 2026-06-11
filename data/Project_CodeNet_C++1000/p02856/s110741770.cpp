#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int m; cin >> m;
  ll D = 0; ll S = 0;
  for(int i = 0; i < m; i++){ 
    ll d,c; cin >> d >> c;
    D += c;
    S += d*c;
  }
  
  cout << (D-1)+(S-1)/9 << endl;
  
  return 0;
}