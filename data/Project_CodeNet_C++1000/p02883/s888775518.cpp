#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N),F(N);
  for(ll i = 0; i < N; i++) cin>>A[i];
  for(ll i = 0; i < N; i++) cin>>F[i];
  sort(A.begin(),A.end());
  sort(F.begin(),F.end());
  reverse(F.begin(),F.end());
  ll M=0,m=-1;
  vector<ll> T(N);
  for(ll i = 0; i < N; i++){
    ll t = A[i]*F[i];
    T[i]=t;
    chmax(M,t);
  }
  while(M-m>1){
    ll mid = (M+m)/2;
    ll cnt = 0;
    for(ll i = 0; i < N; i++){
      if(mid<T[i]){
        cnt+=(T[i]-mid-1)/F[i]+1;
      }
    }
    if(cnt>K)m=mid;
    if(cnt<=K)M=mid;
  }
  cout<<M<<endl;
}