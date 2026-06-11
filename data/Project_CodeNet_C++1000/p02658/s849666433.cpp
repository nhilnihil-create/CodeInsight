#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000000000000

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  long long ans = 1;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i = 0; i < n; i++){
    if(ans > MOD / a[i]){
      cout << -1 << endl;
      return 0;
    }
    ans *= a[i];
  }
  cout << ans << endl;
}