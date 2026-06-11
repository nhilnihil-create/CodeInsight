#include<bits/stdc++.h>
using namespace std;
int main(){
  int A, B;
  cin >> A >> B;
  int C, D;
  cin >> C >> D;
  int ans = 0;
  if(A != C && D == 1){
    ans = 1;
  }
  cout << ans << endl;
}