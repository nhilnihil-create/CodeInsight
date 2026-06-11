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
  ll N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];
  vector<ll> B(N+1);
  rep(i,N) B[i+1]=B[i]+A[i];
  ll ans=B[N];
  rep(i,N){
    ans=min(ans,abs(B[N]-B[i]*2));
  }
  cout<<ans<<endl;
}