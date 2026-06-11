#include<iostream>
#include<cmath>
#include<numeric>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define ll long long
#define modbig (10*10*10*10*10*10*10*10*10+7)
using namespace std;

ll order2(ll n){
  if(n%2!=0)
    return 0;    
  return 1+order2(n/2);
}

ll gcd(ll a,ll b){
  if(a<b){
    ll tmp=a; a=b; b=tmp;
  }
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int main(){
  ll m,n,bunki=0,bunki2=0;
  cin>>n>>m;
  ll a[n],b[n];
  cin>>a[0];
  a[0]/=2;
  b[0]=order2(a[0]);
  rep1(i,n){
    cin>>a[i];
    a[i]/=2;
    b[i]=order2(a[i]);
    if(b[i]!=b[0]){
      bunki=1;
    }
  }
  if(bunki){
    cout<<0;
  }else{
    ll lcm=a[0];
    rep1(i,n){
      lcm/=gcd(lcm,a[i]);
      lcm*=a[i];
      if(lcm>m){
        bunki2=1;
        break;
      }
    }
    if(bunki2==1){
      cout<<0;
    }else{
      cout<<setprecision(12)<<floor(((double)m+lcm)/2/lcm);
    }
  }
}
