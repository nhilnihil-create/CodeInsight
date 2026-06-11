#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;

int main(){
  string s;
  cin >>s;
  if (s.size()%2==1){
    cout<<"No"<<endl;
    return 0;
  }
  rep(i,s.size()){
    if(i%2==0){//h
      if(s[i]!='h'){
        cout<<"No"<<endl;
        return 0;
      }
    
    }else{//i
      if(s[i]!='i'){
        cout<<"No"<<endl;
        return 0;
      }
      
    }
    
  }
  cout<<"Yes"<<endl;
  return 0;
  
  
}
