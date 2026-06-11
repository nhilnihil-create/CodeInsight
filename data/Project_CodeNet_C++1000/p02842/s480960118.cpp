#include <bits/stdc++.h>
using namespace std;

int main(){
  double N;
  cin >> N;
  
  int ans = N * 100 / 108;
  while (ans <= N){
    if (ans * 108 / 100 == N){
      cout << ans << endl;
      exit(0);
    }
    ans++;
  }
  
  cout << ":(" << endl;
}