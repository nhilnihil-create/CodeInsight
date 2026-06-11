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
 
 
  string s;
  cin>>s;
  ll n=s.size();
  rep(i,n){
      if(s[i]!=s[n-1-i]){
          cout<<"No"<<endl;
          return 0;
      }
  }
  
  rep(i,(n-1)/2){
     if(s[i]!=s[(n-1)/2-1-i]){
          cout<<"No"<<endl;
          return 0;
      } 
  }
  
  cout<<"Yes"<<endl;
  
  
 
}

