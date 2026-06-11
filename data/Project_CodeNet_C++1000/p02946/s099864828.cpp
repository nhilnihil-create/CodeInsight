#include <bits/stdc++.h>
using namespace std;

int main(){
  int k, x;
  cin >> k >> x;
  for(int i= max(-1000000, x-k+1); i<= min(1000000, x+k-1); ++i){
    if(i == min(1000000, x+k-1)) cout << i << endl;
    else cout << i << " ";
  }
}