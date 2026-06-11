#include<bits/stdc++.h>
using namespace std;

long long func(int N){
  if(N==0){
    return 0;
  }
  return N+func(N-1);
}

int main(){
  int N;
  cin >> N;
  cout << func(N-1) << endl;
}