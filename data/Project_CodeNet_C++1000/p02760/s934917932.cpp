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
 
 
  vector<vector<ll>>b(3,vector<ll>(3));
  rep(i,3){
      rep(l,3){
          cin>>b[i][l];
      }
  }
  
  ll n;
  cin>>n;
  
  rep(i,n){
      ll a;
      cin>>a;
       rep(l,3){
           rep(m,3){
               if(b[l][m]==a)b[l][m]=0;
           }
       }
  }
  
  rep(i,3){
      rep(m,3){
          if(b[i][m]!=0){
              break;
          }
          if(m==2){
              cout<<"Yes"<<endl;
              return 0;
          }
      }
  }
  
  rep(i,3){
      rep(m,3){
          if(b[m][i]!=0){
              break;
          }
          if(m==2){
              cout<<"Yes"<<endl;
              return 0;
          }
      }
  }
  
  rep(i,3){
          if(b[i][i]!=0){
              break;
          }
          if(i==2){
              cout<<"Yes"<<endl;
              return 0;
          }
  }
  
  for(ll i=2;0<=i;i--){
          if(b[2-i][i]!=0){
              break;
          }
          if(i==0){
              cout<<"Yes"<<endl;
              return 0;
          }
  }
  cout<<"No"<<endl;
}

