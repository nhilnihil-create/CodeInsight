#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
using namespace std;

int main(){
  
  int N;
  cin >> N;
  ll A[N];
  ll multi = 1;

  bool can = false;
  ll cant = pow(10,18);
  for (int i=0; i<N; i++){
    cin >> A[i];
    if (A[i] == 0) {cout << 0 << endl; return 0;}
  }

  for (int i=0; i<N; i++){
    if (cant/A[i] < multi) {can = true; break;}
    multi *= A[i];
  }
  
  if (can) cout << "-1" << endl;
  else cout << multi << endl;
  
  return 0;
}
