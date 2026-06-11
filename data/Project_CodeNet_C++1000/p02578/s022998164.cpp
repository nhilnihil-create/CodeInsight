#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  int MaxNum = 0;
  for(int i = 0; i < n; i++){
    MaxNum = max(MaxNum, a[i]);
    int Bi = MaxNum;
    ans += Bi - a[i];
  }
  cout << ans << endl;
  return 0;
}