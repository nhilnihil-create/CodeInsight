#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> res(n+1), a(n);
  int cnt = 0;
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    if(i >= n/2){
      res.at(i+1) = a.at(i);
      if(res.at(i+1) == 1) cnt++;
    }
  }
  for(int i = n/2; i > 0; i--){
    int cnt1 = 2;
    while(cnt1 * i <= n){
      res.at(i) += res.at(i*cnt1);
      cnt1++;
      res.at(i) %= 2;
    }
    if((a.at(i-1) + res.at(i))%2 == 0) res.at(i) = 0;
    else{
      res.at(i) = 1;
      cnt++;
    }
  }
  cout << cnt << endl;
  for(int i = 1; i <= n; i++){
    if(res.at(i)) cout << i << " ";
  }
}