#include<bits/stdc++.h>
using namespace std;
int main(){
  int ans = 15;
  for (int i = 0; i < 5; i++){
    int x;
    cin >> x;
    ans = ans - x;
  }
  cout << ans << endl;
}
