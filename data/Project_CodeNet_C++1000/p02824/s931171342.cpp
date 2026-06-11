#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, M, V, P;
  cin>>N>>M>>V>>P;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  ll l=0, r=N-1, m;
  ll score;
  bool can;
  while(l<r){
    m = (l+r)/2;
    if(m>=N-P){
      r = m;
      continue;
    }
    score = M*V;
    score -= M*(m+1);
    score -= M*(P-1);
    can = true;
    for(int i=m+1;i<=N-P;++i){
      if(A[m]+M<A[i]) can = false;
      score -= A[m]+M-A[i];
    }
    if(can && score<=0){
      r = m;
    }
    else{
      l = m+1;
    }
  }
  cout<<N-l<<endl;
}

