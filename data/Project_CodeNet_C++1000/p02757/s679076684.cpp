#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, p;
  string s;
  cin >> n >> p >> s;
  long long ans = 0;
  if(p == 2 || p == 5 ){
    for(int i=0; i<n; ++i){
      if((s[i]-'0')%p == 0){
        ans += i+1;
      }
    }
    cout << ans << endl;
    return 0;
  }
  map<int, int> mp;
  ++mp[0];
  int rui = 0;
  int keta = 1;
  for(int i=n-1; i>=0; --i){
    rui += (s[i]-'0') * keta;
    rui %= p;
    keta *= 10;
    keta %= p;
    ans += mp[rui];
    ++mp[rui];
  }
  cout << ans << endl;
}