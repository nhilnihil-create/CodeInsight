#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k,x;
  cin >> k >> x;
  
  for(long long i = x-k+1; i <= x+k-1; i++){
    if(i==x+k-1){
      cout << i << endl;
    }
    else{
      cout << i << ' ';
    }
  }
}