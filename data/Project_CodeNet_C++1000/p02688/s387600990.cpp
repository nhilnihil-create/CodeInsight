#include<bits/stdc++.h>
using namespace std;

int main (void){
  int a,d,n,k,ans = 0;
  int have[110] = {};

  cin >> n >> k;

  for(int i = 0;i < k;i++){
    cin >> d;
    for(int j = 0;j < d;j++){
      cin >> a;
      a--;
      have[a]++;
    }
  }

  for(int i = 0;i < n;i++){
    if(have[i] == 0){
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;

}