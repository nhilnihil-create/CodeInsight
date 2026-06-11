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
int main(void){
  long long int n;
  cin>>n;
  vector<long long int> a(n);
  for(long long int i=0; i<n; i++){
    cin>>a.at(i);
  }
  vector<long long int> pre(n,0);
  vector<long long int> hoge;
  long long int ans=0;
  for(long long int i=n-1; i>=0; i--){
    long long int now=0;
    long long int step=1;
    long long int start=n-n%(i+1)-1;
    for(long long int j=start; j>i; j-=step){
      if((j+1)%(i+1)==0){
        step=i+1;
        now+=pre.at(j);
      }
    }
    if(now%2!=a.at(i)){
      ans++;
      hoge.push_back(i+1);
      pre.at(i)=1;
    }
  }
  cout<<ans<<endl;
  for(long long int i=0; i<hoge.size(); i++){
    cout<<hoge.at(i)<<endl;
  }
}