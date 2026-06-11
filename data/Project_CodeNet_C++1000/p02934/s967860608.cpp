#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n;
  double m;
  cin>>n;

  double sum;
  
  rep(i,n){
      cin>>m;
      sum+=1/m; 

  }
  
  cout<<setprecision(10)<<1/sum<<endl;
}