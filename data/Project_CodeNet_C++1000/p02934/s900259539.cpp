#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
typedef long double ld;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j;
  ld result=0;
  ld a[200010];
  string s;
  cin >> n;
  rep(i,n){
    cin >> a[i];
    result += 1.0 / a[i];
  }
  cout << fixed << setprecision(16) << 1.0/result << endl;
  return 0;
}