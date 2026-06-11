#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (ll i = 0; i < (ll)n; i++)
#define all(x) (x).begin(), (x).end()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end());
// map<int,int> mp;

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N), C(N);
  REP(i, N) cin >> A.at(i);

  REP(i, N) cin >> B.at(i);
  REP(i, N) cin >> C.at(i);

 int ans=B[A[0]-1];
 
for(int i = 1; i < N; i++) {
  ans += B[A[i]-1];
  if(A[i]-A[i-1]==1){
    
    ans +=C[A[i]-2];

  }

  }

  cout << ans << endl;
}


