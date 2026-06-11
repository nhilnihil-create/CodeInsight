#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define io std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n){ll r=1%P;for (a%=P; n; a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
const double eps=1e-5;

bool check(double x,double y)
{
       if(abs(x)<=eps&&abs(y)<=eps)
        return 1;
      return 0;
}
int main()
{
  double x;
  cin>>x;
  x=x/360*2*pi;
  double t=x;
  double xx,yy;
  xx=0;
  yy=1;
  int k=0;
  int s;
  while(!check(xx,yy))
  { 
    xx+=sin(x);
    yy+=cos(x);
    x+=t;
    if(x>=2*pi) x-=2*pi;
    
    k++;
  
  }
  cout<<k+1<<endl;
}
