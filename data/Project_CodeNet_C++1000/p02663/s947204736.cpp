#include <bits/stdc++.h>
using namespace std;

int main(){
  int Wh,Wm,Sh,Sm;
  int K;
  cin >> Wh >> Wm >> Sh >> Sm >> K;
  
  int W,S;
  W = Wh*60+Wm;
  S = Sh*60+Sm;
  
  cout << S-W-K << endl;
}