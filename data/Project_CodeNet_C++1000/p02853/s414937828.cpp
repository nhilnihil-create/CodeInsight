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
  intl X,Y;
  cin >>X>>Y;
  intl money = 0;
  if(X == 1){
    money +=300000;
  }
  if(X==2){money += 200000;}
  if(X==3){money += 100000;}
  if(Y == 1){
    money +=300000;
  }
  if(Y==2){money += 200000;}
  if(Y==3){money += 100000;}
  if(X==1 &&Y==1){money += 400000;}
  cout <<money;

}