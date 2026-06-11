#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int Th, Ta, Ah, Aa;
  cin >> Th >> Ta >> Ah >> Aa;
  
  while(true){
  Ah -= Ta;
  if(Ah <= 0){
    cout << "Yes" << endl;
    break;
  }
  Th -= Aa;
  if(Th <= 0){
    cout << "No" << endl;
    break;
  }
  }
  return 0;
}