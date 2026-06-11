#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=0; i<=n; ++i){
    int x = i *108 /100;
    if(x == n){
      cout << i << endl;
      return 0;
    }
    else if(x > n) break;
  }
  cout << ":(" << endl;
}