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

ll gcd(ll A,ll B){
  if(B==0) return A;
  return gcd(B,A%B);
}

int main(){
  ll N,M;
  cin>>N>>M;
  VL A(N);
  rep(i,N) cin>>A[i];
  int F=0;
  rep(i,N) F|=A[i]%2;
  if(F){
    cout<<0<<endl;
    return 0;
  }
  ll lcm=1;
  rep(i,N){
    lcm=lcm/gcd(lcm,A[i])*A[i];
    if(lcm>M*2){
      cout<<0<<endl;
      return 0;
    }
  }
  rep(i,N){
    if(lcm/A[i]%2==0){
      cout<<0<<endl;
      return 0;
    }
  }
  lcm/=2;
  cout<<(M/lcm+1)/2<<endl;
}