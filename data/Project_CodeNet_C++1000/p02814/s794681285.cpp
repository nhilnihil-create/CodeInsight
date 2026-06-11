#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
#define lcm(a,b) (((a)/gcd(a,b))*(b))
ll log_two(int n){
  if(n==0 || n%2==1) return 0;
  else return log_two(n/2)+1;
}
int main(){
  ll n,m,k,i,j,result=0,t;
  int a[200010];
  cin >> n >> m;
  t=1;
  rep(i,n){
    cin >> a[i];
    if(i==0){
      k = log_two(a[i]);
      t = a[i]/2;
    }else if(t==0 || k != log_two(a[i])){
      t=0;
    }else{
      a[i] /= 2;
      t = lcm(a[i],t);
    }
    //cout << t << endl;
  }
  if(t==0) cout << 0 << endl;
  else cout << (m/t-m/(2*t)) << endl;
  
  return 0;
}