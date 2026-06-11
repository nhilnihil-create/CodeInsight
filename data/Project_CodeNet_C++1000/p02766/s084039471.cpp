#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main(){
  int n, k, d=1, ans=0;
  cin >> n >> k;
  while(n>=d){
    d*=k; 
    ans++;
  }
  cout << ans << endl;
  return 0;
}