#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll N;cin>>N;
  vector<pair<ll,ll>> A(N+1);rep(i,N) cin>>A[i+1].first;
  for(int i=1;i<=N;i++) A[i].second=i;
  A[0].first=0;A[0].second=0;
  
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  
  if(A[0].first==A[1].first){
    rep(i,N) cout << A[0].first << endl;
    return 0;
  }
  
  else{
	for(int i=0;i<A[0].second-1;i++) cout << A[0].first << endl;
    cout << A[1].first << endl;
    for(int i=1;i<=N-A[0].second;i++) cout << A[0].first << endl;
  }
}
 