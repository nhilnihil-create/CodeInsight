#include<bits/stdc++.h>
using namespace std;

int func(int A){
  return A*(A-1)/2;
}

int main(){
  int N,M;
  cin >> N >> M;
  cout << func(N)+func(M) << endl;
}
  
  