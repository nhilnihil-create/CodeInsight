#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using vb=vector<bool>;
using vvb=vector<vb>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i,N) cin >> A[i];
  
  vi x(N);
  ll sum=0;
  rep(i,N/2) sum+=A[2*i]-A[2*i+1];
  sum+=A[N-1];
  x[0]=sum/2;
  rep(i,N-1) x[i+1]=A[i]-x[i];
  
  rep(i,N) cout << 2*x[i] << ' ';
  cout << endl;
}