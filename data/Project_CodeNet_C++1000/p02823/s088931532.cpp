#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  if(!((B-A)%(ll)2)) cout << (B-A)/(ll)2 << endl;
  else {
    ll X=min(A-1,N-B);
    cout << X+1+(B-A-1)/(ll)2 << endl;
  }
}