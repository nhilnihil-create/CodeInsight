#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n;
  double sum;
  cin>>n;
  
  vector <double> vec(n);
  rep(i,n){
      cin>>vec[i]; 
  }
  
  
  
  sort(vec.begin(),vec.end());
  
  rep(i,n-1){
    vec[i+1]=(vec[i]+vec[i+1])/2;
    
  }
  cout<<vec[n-1];
}