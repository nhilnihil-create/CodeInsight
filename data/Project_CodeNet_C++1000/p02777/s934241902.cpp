#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B,E;
  int C,D;
  cin >> A >> B >> C >> D >> E;
  if(E==A){
    C--;
  }
  else{
    D--;
  }
  cout << C <<" " << D<< endl;
}