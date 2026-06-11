
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int ans;
  int b;
  for(int i = n; i <= 200000; i++){
    b = 1;
    for(int j = 2; j <= (int)sqrt(i); j++){
      if(i % j == 0){
        b = 0;
        break;
      }
    }
    if(b){
      ans = i;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}