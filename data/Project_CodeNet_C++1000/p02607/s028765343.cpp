#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, sum=0;
  cin >> n;
  
  for(int i=1; i <= n; i++){
    cin >> a;
    if((a % 2) == 1){
      if((i % 2) == 1){
        sum++;
      }
    }
  }
  cout << sum << endl;
}