#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

ll gcd(ll a, ll b) {
  if(a<b) return gcd(b,a);
  if(b==0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  return a*b/gcd(a,b);
}

int main()
{
  ll a, b;
  cin>>a>>b;

  cout<<lcm(a,b)<<endl;

  return 0;
}