#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
template<class T,class C> T max(T a,C b){ return ((a)>(T)(b) ? (a) : (T)(b)); }
template<class T,class C> T min(T a,C b){ return ((a)<(T)(b) ? (a) : (T)(b)); }
typedef long long ll;
typedef long double ld;
#define LLINF (1LL<<60)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0,sum=0;
  int a[200010]={0};
  string s;
  
  cin >> n;
  rep(i,n){
    cin >> a[i];
    sum += (ll)a[i];
  }
  result = LLINF;
  j=0;
  rep(i,n){
    j += (ll)a[i];
    sum -= (ll)a[i];
    result = min(result,llabs(j-sum));
  }
  
  cout << result << endl;
  return 0;
}