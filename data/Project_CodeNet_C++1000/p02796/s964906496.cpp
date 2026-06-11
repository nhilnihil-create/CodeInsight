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
  vector<pair<long long int,long long int>> hoge(n);
  for(int i=0; i<n; i++){
    long long int s,t;
    cin>>s>>t;
    hoge.at(i).first=s+t;
    hoge.at(i).second=s-t;
  }

  sort(hoge.begin(),hoge.end());
  long long int ans=1;
  long long int last=hoge.at(0).first;
  for(long long int i=1; i<n; i++){
    if(hoge.at(i).second<last){
      
    }else{
      ans++;
      last=hoge.at(i).first;
    }
  }
  cout<<ans<<endl;
}