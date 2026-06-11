#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, ans = 0, tap = 1;
  cin >> A >> B ;
  while(tap < B) {
    tap += A - 1;
    ans++;
  }
  cout << ans << endl;
  
}
