#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

int main(){
  ll N; cin >> N;
  ll A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A,A+N);
  ll ans = 0;
  for(int i=1;i<N;i++){
    ll x = i/2;
    ans += A[N-1-x];
  }
  cout << ans << endl;
}

