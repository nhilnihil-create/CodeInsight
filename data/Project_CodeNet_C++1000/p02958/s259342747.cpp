#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i,n){
    cin >> vec[i];
  }
  int ans = 0;
  rep(i,n){
    if(vec[i] != i+1){
      if(vec[vec[i]-1] != i+1){
        cout << "NO";
        return 0;
      }
      ans++;
    }
  }
  
  if(ans >= 3){
    cout << "NO";
  }
  else{
  cout << "YES";
  }
  return 0;
}