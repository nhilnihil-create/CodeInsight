#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pf push_front
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ub upper_bound
#define lb lower_bound

int main(){
  int N,K,C;
  cin>>N>>K>>C;
  string S;
  cin>>S;
  VI L(0),R(0);
  int tmp=-1;
  rep(i,N){
    if(tmp>i) continue;
    if(S[i]=='o'){
      L.pb(i);
      tmp=i+C+1;
    }
  }
  tmp=-1;
  rep(i,N){
    if(tmp>i) continue;
    if(S[N-1-i]=='o'){
      R.pb(N-1-i);
      tmp=i+C+1;
    }
  }
  VI LL(N+1),RR(N+1);
  rep(i,L.size()) LL[L[i]+1]++;
  rep(i,R.size()) RR[R[i]]++;
  rep(i,N) LL[i+1]+=LL[i];
  rep(i,N) RR[N-1-i]+=RR[N-i];
  rep(i,N) if(LL[i]+RR[i+1]<K) cout<<i+1<<endl;
}