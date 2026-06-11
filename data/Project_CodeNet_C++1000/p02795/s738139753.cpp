#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(intl i=0;i<(intl)(n);i++)
#define Rep1(i,n) for(intl i=1;i<(intl)(n)+1;i++)
#define vec vector
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define SortA(v) sort(v.begin(), v.end())
#define SortD(v) sort(v.rbegin(), v.rend())
#define All(a) (a).begin(),(a).end()
using intl = int64_t;
using vi = vec<intl>;
using vvi = vec<vi>;
using pi = pair<intl,intl>;
using vpi = vec<pi>;
vec<intl> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<intl> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr intl INF = 9223372036854775807;


int main(){
  int H,W,N;
  cin >>H>>W>>N;
  intl use = max(H,W);
  cout << N/use + ((N%use)?1:0) ;
}