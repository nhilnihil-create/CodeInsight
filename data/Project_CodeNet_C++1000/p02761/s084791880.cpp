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
  ll n,m;
  cin>>n>>m;
  string s(n,'a');
  int b;
  char c;
  
  rep(i,m){
    cin>>b>>c;
    if(s[b-1]=='a'){
        s[b-1]=c;
    }else{
        if(s[b-1]==c){
            s[b-1]=c;
        }else{
           
            cout<<-1<<endl;
            return 0;
            
        }
    }
  }
  
  if(s[0]=='a'){
      if(n==1)s[0]='0';
      else s[0]='1';
  }
  
  if(s[0]=='0'&&n!=1){
      cout<<-1<<endl;
      return 0;
  }
 
  rep(i,n){
      if(s[i]=='a'){
          cout<<'0';
      }else{
          cout<<s[i];
      }
      if(i==n-1){
          cout<<endl;
      }
  }
       
  
}

