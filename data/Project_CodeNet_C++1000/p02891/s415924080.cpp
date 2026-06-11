#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  string s;
  cin>>s;
  long long int k;
  cin>>k;
  vector<int> hoge(1,0);
  int itr=0;
  for(int i=0; i<s.length(); i++){
    if(i==0){
      hoge.at(0)++;
    }else if(s[i]==s[i-1]){
      hoge.at(itr)++;
    }else{
      itr++;
      hoge.push_back(1);
    }
  }
  long long int ans=0;
  bool both=false;
  if(s[0]==s[s.length()-1]){
    both=true;
  }
  for(int i=0; i<hoge.size(); i++){
    if(both&&(i==0||i==hoge.size()-1)){
      ans+=hoge.at(i)/2;
      continue;
    }
    ans+=(hoge.at(i)/2)*k;
  }
  if(s[0]==s[s.length()-1]){
    int sum=hoge.at(0)+hoge.at(hoge.size()-1);
    ans+=(sum/2)*(k-1);
  }
  if(s.length()==1){
    ans=k/2;
  }
  if(hoge.size()==1){
    ans=hoge.at(0)*k/2;
  }
  cout<<ans<<endl;
}