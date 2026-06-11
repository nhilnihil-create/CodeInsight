#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(int i=(ll)(b);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll m,d;cin>>m>>d;
  ll res=0;
  repi(i,1,m+1){
    repi(j,1,d+1){
      ll da=j%10,db=j/10;
      if(da<2||db<2)continue;
      if(i==da*db){res++;}
    }
  }
  cout<<res<<endl;

  return 0;

}
