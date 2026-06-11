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
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

vector<ll> Gauss(vector<ll> A){
    int rank=0;
    for(int i=60;i>=0;i--){
        int pivot=-1;
        for(int j=rank;j<A.size();j++){
            if(A[j]&(1ll<<i)){
                pivot=j;
                break;
            }
        }
        if(pivot==-1) continue;

        swap(A[rank],A[pivot]);
        for(int j=0;j<A.size();j++) if(j!=rank){
            if(A[j]&(1ll<<i)) A[j]^=A[rank];
        }
        rank++;
    }
    vector<ll> res;
    for(int i=0;i<rank;i++) res.push_back(A[i]);
    return res;
}

int main(){
  int N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  ll all=0;
  rep(i,N) all^=A[i];
  
  vector<ll> B=A;
  for(int i=0;i<N;i++){
      for(int k=0;k<60;k++){
          if((all&(1ll<<k))&&(B[i]&(1ll<<k))) B[i]^=(1ll<<k);
      }
  }

  vector<ll> basis=Gauss(B);

  ll ans=0;
  for(int i=0;i<basis.size();i++){
      if(ans<(ans^basis[i])) ans^=basis[i];
  }
  cout<<ans*2+all<<"\n";

  return 0;
}
