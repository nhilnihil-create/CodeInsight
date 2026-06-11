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
vector<long long int> c;
vector<vector<long long int>> hoge;
vector<long long int> ans;
void saiki(long long int now,long long int bef){
  if(now!=0&&hoge.at(now).size()==1){
    ans.at(now)=c.at(now)+ans.at(bef);
    return;
  }
  ans.at(now)=c.at(now);
  if(now!=0) ans.at(now)+=ans.at(bef);
  for(long long int i=0; i<hoge.at(now).size(); i++){
    if(hoge.at(now).at(i)!=bef){
      saiki(hoge.at(now).at(i),now);
    }
  }
}
int main(void){
  long long int n,q;
  cin>>n>>q;
  hoge=vector<vector<long long int>>(n,vector<long long int>(0));
  c.resize(n);
  ans.resize(n);
  for(long long int i=0; i<n-1; i++){
    long long int a,b;
    cin>>a>>b;
    a--;
    b--;
    hoge.at(a).push_back(b);
    hoge.at(b).push_back(a);
  }
  vector<long long int> p(q);
  vector<long long int> x(q);
  for(long long int i=0; i<q; i++){
    cin>>p.at(i)>>x.at(i);
  }
  for(long long int i=0; i<q; i++){
    c.at(p.at(i)-1)+=x.at(i);
  }
  saiki(0,-1);
  for(long long int i=0; i<n; i++){
    cout<<ans.at(i);
    if(i!=n-1){
      cout<<" ";
    }else{
      cout<<endl;
    }
  }
}