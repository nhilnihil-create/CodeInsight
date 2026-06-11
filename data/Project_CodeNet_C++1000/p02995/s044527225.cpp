#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll gcd(ll a,ll b){
  if(a < b) return gcd(b, a);
    int r;
    while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){

  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll lcd = c/gcd(c,d) * d;
  ll n;
  if(a%c==0)n=(b-a)/c+1;
  else n=b/c-a/c;

  ll m;
  if(a%d==0)m=(b-a)/d+1;
  else m=b/d-a/d;

  ll k;
  if(a%lcd==0)k=(b-a)/lcd+1;
  else k=b/lcd-a/lcd;

  cout << (b-a+1)-n-m+k << endl;



}