#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;
bool LTE(double a,double b) { return equals(a,b) || a < b; }
bool LT(double a,double b) { return !equals(a,b) && a < b; }

#define MAX 310000
int N, A[MAX];

vector<int> convert() {
  map<int,int> mp;
  rep(i,N) ++mp[A[i]];
  vector<int> C;
  for(auto v : mp) C.push_back(v.second);
  sort(ALL(C));
  return C;
}

/*
  K,ans wo kotei
  Sigma( min(C[i],ans) ) / K >= ans de are ba tukure ruru- 
  Sigma( min(C[i],ans) ) >= ans * K 
  Sigma( min(C[i],ans) ) >= ans * K nara Sigma( min(C[i],(ans-1)) ) >= (ans-1) * K 
  binariy search
 */
vector<int> C;
ll sum[MAX];
bool check(ll ans, ll K) {
  int ptr = lower_bound(ALL(C), ans) - C.begin();
  --ptr;
  int rem = (int)C.size() - 1 - ptr;
  ll sigma = sum[ptr] + (ll)rem * ans;
  return sigma >= ans * K;
}

void compute() {
  C = convert();
  sum[0] = C[0];
  REP(i,1,(int)C.size()) sum[i] = sum[i-1] + C[i];
  REP(K,1,N+1) {
    ll L = 1, R = N+1;
    while( R - L ){
      ll ans = ( L + R ) / 2LL;
      if( check(ans,K) ) L = ans + 1LL;
      else               R = ans;
    }
    cout << L - 1LL << endl; 
  }
}

int main() {
  cin >> N;
  rep(i,N) cin >> A[i];
  compute();
  return 0;
}
