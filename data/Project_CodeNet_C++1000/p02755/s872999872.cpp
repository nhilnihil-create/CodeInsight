#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
  // violinista forever xd
  ios::sync_with_stdio(0),cin.tie(0);
  
  ll a,b,rta;	
  cin >> a>>b;
  a *= 100;
  b *= 100;
  rta = -1;
  bool aun = true;
  for (int i = 0; i < 100000 && aun; i++){
    if ((i * 8 - a) < 100 && (i * 8 - a) >= 0){
      if ((i * 10 - b) < 100 && (i * 10 - b) >= 0){
        rta = i;
        aun = false;
      }
    }
  }
  cout << rta << endl;
  return 0;
}