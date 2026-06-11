#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int GCD(int x,int y){
  if(x<y){
    swap(x,y);
  }
  while(x%y!=0){
    int temp=x;
    x=y;
    y=temp%y;
  }
  return y;
}

int digitsum(int x){
  int sum=0;
  while(x>0){
    sum+=(x%10);
    x/=10;
  }
  return sum;
}

int main() {
  int x,y,z;
  cin>>x>>y>>z;
  swap(x,y);swap(x,z);
  cout<<x<<' '<<y<<' '<<z<<endl;
  return 0;
}
