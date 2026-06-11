#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
typedef long double ld;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0;
  int a[200010]={0};
  string s;
  cin >> n;
  rep(i,n) cin >> a[i];
  m=0;
  rep(i,n){
    if(a[i]!=i+1) m++;
  }
  cout << (m<=2 ? "YES" : "NO") << endl;
  return 0;
}