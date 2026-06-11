#include <bits/stdc++.h>
using namespace std;
int main(){
  long n,k;cin >> n >> k;
  vector<long>h(n);
  long  ans = 0;
  for(int i = 0; i < n; i++)
    cin >>h.at(i);
  sort(h.begin(), h.end());
  reverse(h.begin(), h.end());
  for(int i = 0; i < n; i++){
    if(k > 0){
      k--;
    }
    else
      ans += h.at(i);
  }
  cout << ans;
}