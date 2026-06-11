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
  long long int all=0;
  vector<long long int> a(n);
  for(long long int i=0; i<n; i++){
    cin>>a.at(i);
    all+=a.at(i);
  }

  vector<long long int> ans(n);
  ans.at(0)=all;
  for(long long int i=1; i<=n-2; i+=2){
    ans.at(0)-=2*a.at(i);
  }

  for(long long int i=1; i<n; i++){
    ans.at(i)=2*a.at(i-1)-ans.at(i-1);
  }
  for(long long int i=0; i<n; i++){
    cout<<ans.at(i);
    if(i==n-1){
      cout<<endl;
    }else{
      cout<<" ";
    }
  }
}