#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  ll a,b;
  cin >> a >> b;
  ll g=gcd(a,b);
  int rg=sqrt(g);
  int i=2,ans=1;
  bool checker=false;
  while(i<=rg){
    while(g%i==0){
      if(!checker){
        checker=true;
        ans++;
      }
      g/=i;
    }
    checker=false;
    i++;
  }
  if(g!=1) ans++;
  cout << ans;
  return 0;
}