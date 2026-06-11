#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  vector<ll>s(N-1);
  rep(i,N-1){
    if(A[i] >= A[i+1]){
      s[i] = 1;
    }
    else{
      s[i] = 0;
    }
  }
  ll count = 0;
  ll ans = 0;
  rep(i,N-1){
    if(s[i]){
      count++;
      ans = max(ans,count);
    }
    else{
      ans = max(ans,count);
      count = 0;
    }
  }
  cout << ans;
}
    