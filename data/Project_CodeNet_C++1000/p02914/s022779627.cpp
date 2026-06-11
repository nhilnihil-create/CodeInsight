#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
vector<ll> A;

void Gauss(vector<ll> &B){//binary
    int rank=0;
    for(int d=59;d>=0;d--){
        int pivot=-1;
        for(int i=rank;i<(int)B.size();i++){
            if(B[i]&(1ll<<d)){
                pivot=i;
                break;
            }
        }
        if(pivot==-1) continue;
        swap(B[rank],B[pivot]);
        for(int j=0;j<(int)B.size();j++){
            if(j<=rank) continue;
            if(!(B[j]&(1ll<<d))) continue;
            B[j]^=B[rank];
        }
        rank++;
    }
}

int main(){
  cin>>N;
  A.resize(N);
  rep(i,N) cin>>A[i];

  ll sum=0;
  for(int i=0;i<N;i++) sum^=A[i];

  vector<ll> B=A;
  for(int i=0;i<N;i++){
      B[i]&=(~sum);
  }

  Gauss(B);

  ll ans=0;
  for(int i=0;i<N;i++){
      ans=max(ans,ans^B[i]);
  }

  ans*=2;
  ans+=sum;

  cout<<ans<<endl;

  return 0;
}
