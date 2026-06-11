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
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

//0-indexed
class BIT{
public:
  int N;
  vector<ll> data;
  BIT(){}
  BIT(int n):N(n),data(n){}

  ll sum(int l,int r){//[l,r)
    return sum(r)-sum(l);
  }

  void add(int p,ll x){
    p++;
    while(p<=N){
      data[p-1]+=x;
      p+=p&(-p);
    }
  }

private:
  ll sum(int r){
      ll s=0;
      while(r>0){
          s+=data[r-1];
          r-=r&(-r);
      }
      return s;
  }
};


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,Q;
  cin>>N>>Q;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  BIT fw(N);
  rep(i,N) fw.add(i,A[i]);

  rep(q,Q){
      int T;
      cin>>T;
      if(T==0){
          int p;ll x;
          cin>>p>>x;
          fw.add(p,x);
      }else{
          int l,r;
          cin>>l>>r;
          cout<<fw.sum(l,r)<<"\n";
      }
  }

  return 0;
}
