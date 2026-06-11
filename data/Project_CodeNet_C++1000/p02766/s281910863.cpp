#include <bits/stdc++.h>
using namespace std;

int main() {
   int N,K;
   cin >> N >> K;
  for(int i = 0; i > -1; i++){
    if(N<K){
      cout << i+1 << endl;
      return 0;
    }
    else{
      N = N/K;
    }
  }
}