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
  int n;
  cin>>n;
  map<int,int> hoge;
  set<int> all;
  for(int i=0; i<n; i++){
    int a;
    cin>>a;
    all.insert(a);
    hoge[a]++;
  }
  if(all.size()==1){
    if(hoge.count(0)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else if(all.size()==2){
    if(hoge[0]==n/3){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else if(all.size()==3){
    int a,b,c;
    auto itr=all.begin();
    a=*itr;
    itr++;
    b=*itr;
    itr++;
    c=*itr;
    int x=a^b;
    int y=x^c;
    if(y==0&&hoge[a]==n/3&&hoge[b]==n/3&&hoge[c]==n/3){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }else{
    cout<<"No"<<endl;
  }
}