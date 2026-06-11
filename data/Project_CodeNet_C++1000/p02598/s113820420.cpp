#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, K;
  cin>>N>>K;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll l=1, r=inf, m;
  int num;
  while(l<r) {
    m = (l+r)/2;
    num = 0;
    for(int i=0;i<N;++i) {
      if(A[i]%m==0) num += A[i]/m-1;
      else num += A[i]/m;
    }
    if(num>K) l = m+1;
    else r = m;
  }
  cout<<l<<endl;
}

