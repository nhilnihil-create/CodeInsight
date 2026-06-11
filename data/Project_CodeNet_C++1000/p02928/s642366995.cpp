#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
long long int mod=1000000007;
int main(void){
  long long int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin>>a.at(i);
  }
  vector<long long int> hoge(n,0);
  vector<long long int> all(n,0);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(a.at(i)>a.at(j)){
        all.at(i)++;
        if(j>i){
          hoge.at(i)++;
        }
      }
    }
  }
  long long int souwa;
  if((k-1)%2==0){
    souwa=k*((k-1)/2);
  }else{
    souwa=k*((k-1)/2)+((k-1)/2+1);
  }
  souwa%=mod;
  long long int ans=0;
  for(int i=0; i<n; i++){
    ans+=hoge.at(i)*k;
    ans%=mod;
    ans+=all.at(i)*souwa;
    ans%=mod;
  }
  cout<<ans<<endl;
}
