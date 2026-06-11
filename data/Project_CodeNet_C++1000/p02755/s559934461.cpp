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
 
 
  ll a,b;
  cin>>a>>b;
  ll ans=b*10;
  rep(i,10){
      if((ans+i)*8/100==a){
          cout<<ans+i<<endl;
          return 0;
      }
  }
 
  cout<<-1<<endl;
}

