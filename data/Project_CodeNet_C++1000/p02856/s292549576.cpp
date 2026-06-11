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
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int M;
  cin>>M;
  vector<ll> D(M),C(M);
  rep(i,M) cin>>D[i]>>C[i];
  ll ans=-1;
  rep(i,M) ans+=C[i];
  ll sum=0;
  rep(i,M) sum+=D[i]*C[i];
  ans+=(sum-1)/9;
  cout<<ans<<endl;
}