#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int ans = 0;
  int total = 0;
  for(int i = 1; i <= n; i++){
    int tmp = i;
    while(tmp > 0){
      tmp /= 10;
      total++;
    }//while
    if(total % 2 == 1){
      ans++;
    }//if
    total = 0;
  }//for
  
  cout << ans << endl;
}