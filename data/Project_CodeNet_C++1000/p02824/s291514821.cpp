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

ll N,M,V,P;
VL A;
bool solve(ll mid){
  if(mid==N) return false;
  if(mid<P) return true;
  if(A[mid]+M<A[P-1]) return false;
  ll sum=(P+N-mid-1)*M;
  rep(i,mid-P+1) sum+=A[mid]+M-A[P-1+i];
  if(sum>=M*V) return true;
  return false;
}

int main(){
  cin>>N>>M>>V>>P;
  ll B;
  rep(i,N){
    cin>>B;
    A.pb(B);
  }
  sort(all(A),greater<ll>());
  ll ng=N;
  ll ok=0;
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    if(solve(mid)) ok=mid;
    else ng=mid;
  }
  cout<<ok+1<<endl;
}