#include <bits/stdc++.h>
using namespace std;
signed gcd(long long x, long long y) {if (y == 0)return x;long long z=gcd(y, x % y);return z;}
int main(){
  long long a,b,c,d; cin>>a>>b>>c>>d;
  cout<<b-a+1-(b/c-(a-1)/c+b/d-(a-1)/d-b/(c/gcd(c,d)*d)+(a-1)/(c/gcd(c,d)*d))<<endl;
}