#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(intl i=0,nn=(intl)(n);i<nn;++i)
#define Rep1(i,n) for(intl i=1,nn=(intl)(n)+1;i<nn;++i)
#define vec vector
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define SortA(v) sort(v.begin(), v.end())
#define SortD(v) sort(v.rbegin(),v.rend())
#define All(a) (a).begin(),(a).end()
#define Input(a) for(intl ii=0,nn=(intl)(a.size());ii<nn;ii++){cin>>(a).at(ii);}
#define Input2(a,b) for(intl ii=0,nn=(intl)(a.size());ii<nn;ii++){cin>>(a).at(ii);cin>>(b).at(ii);}
#define mp make_pair
#define mt make_tuple
using intl = int64_t;
using vi = vec<intl>;
using vvi = vec<vi>;
using pi = pair<intl,intl>;
using vpi = vec<pi>;
using si = set<intl>;
using vsi = vec<si>;
using mii = map<intl,intl>;
using vmii = vec<mii>;
vec<intl> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<intl> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr intl INF = 9223372036854775807;



int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  intl N;
  cin >>N;
  vi nums(N+1,0);
  vi A(N+1);
  Rep1(i,N){
    cin >>A[i];
    nums[A[i]] ++;
  }
  
  intl all =0;
  Rep1(i,N){
    all += nums[i]*(nums[i]-1)/2;
  }
  Rep1(i,N){
    cout << all - ( (nums[A[i]])?nums[A[i]]-1:0)<<'\n';
  }
}
  