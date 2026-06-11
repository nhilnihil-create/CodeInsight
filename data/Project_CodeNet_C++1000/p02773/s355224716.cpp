#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n,a,m;
  cin>>n;
  a=0;
  m=0;
  vector<string> vec(n);
  for(int64_t i=0;i<n;i++){
  cin>>vec.at(i);
  }
  sort(vec.begin(), vec.end());
  for(int64_t i=0;i<n-1;i++){
  if(vec.at(i)==vec.at(i+1)){a++;
                            m=max(m,a);}
    else{a=0;}
  }
  if(a!=0){a=0;
  for(int64_t i=0;i<n-1;i++){
  if(vec.at(i)==vec.at(i+1)){a++;
                            if(m==a){cout<<vec.at(i)<<endl;};}
    else{a=0;
         }
  }}
  else{for(int64_t i=0;i<n;i++){
  cout<<vec.at(i)<<endl;
  }}
 }