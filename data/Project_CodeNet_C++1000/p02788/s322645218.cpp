#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,D,A;
  cin>>N>>D>>A;
  VI X(N),H(N);
  rep(i,N) cin>>X[i]>>H[i];
  vector<PII> P(N);
  rep(i,N) P[i]=mp(X[i],H[i]);
  sort(all(P));
  rep(i,N){
    X[i]=P[i].first;
    H[i]=P[i].second;
  }
  VL cnt(N+1);
  VI R(N);
  rep(i,N) R[i]=ub(all(X),X[i]+D*2)-X.begin()-1;
  ll ans=0;
  rep(i,N){
    if(i) cnt[i]+=cnt[i-1];
    ll tmp=(max(0ll,H[i]-cnt[i]*A)+A-1)/A;
    ans+=tmp;
    cnt[i]+=tmp;
    cnt[R[i]+1]-=tmp;
  }
  cout<<ans<<endl;
}