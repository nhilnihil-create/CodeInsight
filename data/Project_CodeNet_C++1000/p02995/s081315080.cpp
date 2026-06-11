#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;

ll gcd(ll a,ll b){
  if(a%b==0)return b;
  else return gcd(b,a%b);
}

int main(){
  ll a,b,c,d;
  cin >>a>>b>>c>>d;
  ll total=b-a+1;
  ll cd=c*d/gcd(c,d);
  ll tmp1=b/c-(a-1)/c;
  ll tmp2=b/d-(a-1)/d;
  ll tmp3=b/cd-(a-1)/cd;
  cout <<total-tmp1-tmp2+tmp3<<endl;
}