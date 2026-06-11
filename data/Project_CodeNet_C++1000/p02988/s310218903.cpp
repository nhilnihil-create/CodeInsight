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
  int ans;
  ans = 0;
  
  for(int i = 1; i < n - 1; i++){
    if(vec[i-1] < vec[i] && vec[i] < vec[i+1]){
      ans++;
    }
    else if(vec[i-1] > vec[i] && vec[i] > vec[i+1]){
      ans++;
    }
   }
            cout << ans;
  return 0;
}