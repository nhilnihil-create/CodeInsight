#include <iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
#define ld long double
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main(void){
    // Your code here!

  ll a,b;
  ll c,d;
  cin>>a>>b>>c>>d;
  
  ll z= (c)/__gcd(c,d)*d;
  
  ll x1= (a-1)/c;
  ll y1= b/c;
  ll x2= (a-1)/d;
  ll y2= b/d;
  ll x3 =(a-1)/z;
  ll y3= b/z;
  
//  cout<<x1<<y1<<" "<<x2<<y2<<" "<<x3<<y3;
  
  cout<<(b-a+1)-((y1-x1)+ (y2-x2)-(y3-x3));
  
  
}
