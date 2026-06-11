#include <bits/stdc++.h>

using namespace std;

int main(){
  int N,D;
  cin >> N >> D;
  int mp=2*D+1;
  
  int a=N/mp;
  
  N=N-a*mp;
  if(N>0){
    cout << a+1 << endl;
  }
  else{
    cout << a << endl;
  }
}