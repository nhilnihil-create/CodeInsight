#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

lint fact(lint n,lint p){
  lint r=1;
  REP(i,n){
    r*=i+1;
    r%=p;
  }
  return r;
}

lint pow_mod(lint a,lint b,lint p){
  if(b==0)return 1;
  if(b%2==0){
    lint d=pow_mod(a,b/2,p);
    return (d*d)%p;
  }else{
    return (a*pow_mod(a,b-1,p))%p;
  }
}

//x / a mod p=x * inv_mod(a,p) 
lint inv_mod(lint a,lint p){
  return pow_mod(a,p-2,p);//(a^(p-2))mod p
}

using namespace std;
lint p=1e9+7;
int main(){
  lint S;
  cin>>S;
  lint ans=0;
  REP(i,S){
    if(S-3-3*i<0)break;
    lint temp=fact(S-3-2*i,p);
    temp*=inv_mod(fact(S-3-3*i,p),p);
    temp%=p;
    temp*=inv_mod(fact(i,p),p);
    temp%=p;
    ans+=temp;
    ans%=p;
  }
  cout<<ans<<endl;
  return 0;
}
