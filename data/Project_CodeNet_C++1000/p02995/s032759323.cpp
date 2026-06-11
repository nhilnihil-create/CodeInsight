#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a,ll b){
  while(a*b!=0){
    if(a>b){
      a=a%b;
    }else{
      b=b%a;
    }
  }
  return a+b;
}

int main(){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  ll l=c/gcd(c,d)*d;
  ll s=l-l/c-l/d+1;
  ll ta=((a-1)%l)-((a-1)%l)/c-((a-1)%l)/d;
  ll tb=(b%l)-(b%l)/c-(b%l)/d;
  cout << (b/l)*s+tb-((a-1)/l)*s-ta << endl;
}