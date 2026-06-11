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
  intl N,M;
  cin >>N>>M;
  //if(M==0&&N==1){ cout <<"0";return 0;}
  //if(M==0&&N==2){cout << "10";return 0;}
  //if(M==0&&N==3){cout << "100";return 0;}
  vi s(M),c(M);
  Input2(s,c);
  intl ans = -1;
  Rep(i,1000){
    string I = to_string(i);
    bool OK = 1;
    if(I.size() != N){OK=0;continue;}
    Rep(j,M){
      if(I.size() < s[j]){OK=0;break;}
      if(I.at(s[j]-1) != '0'+c[j]){OK=0;break;}
    }
    if(OK){ans = i;break;}
  }
  
  cout <<ans;
}
    
    