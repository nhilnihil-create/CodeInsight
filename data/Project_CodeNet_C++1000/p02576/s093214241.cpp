#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, X, T, count;
  cin >> N >> X >> T;
  if(N % X != 0){
    cout << T*(N/X+1) << endl;
  }else{
    cout << T*N/X << endl;
  }
  return 0;
}