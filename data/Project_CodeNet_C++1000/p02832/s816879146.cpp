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
  long long int now=1;
  long long int ans=0;
  for(long long int i=0; i<n; i++){
    if(a.at(i)==now){
      now++;
    }else{
      ans++;
    }
  }
  if(ans==n){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
}