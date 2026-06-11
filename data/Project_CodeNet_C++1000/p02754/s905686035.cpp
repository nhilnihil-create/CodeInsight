#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)

int main(){
 
 
  ll n,a,b;
  cin>>n>>a>>b;
  ll sum=0;
  ll ans=0;
  ans+=n/(a+b)*a;
  if(n%(a+b)<=a){
      ans+=n%(a+b);
  }else{
      ans+=a;
  }
  cout<<ans<<endl;
  
  
  
  

  
  
 
}

