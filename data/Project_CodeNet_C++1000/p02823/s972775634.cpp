#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll N, A, B, ans;
  cin >> N >> A >> B;
  if(A>B) swap(A, B);
  if((B-A)%2==0) ans = (B-A)/2;
  else ans =min(A-1,N-B)+1+(B-A-1)/2;
  cout << ans << endl;
  return 0;
}