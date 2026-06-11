#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,k,r,s,p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  
  int i,a=0;
  for(i=0;i<k;i++){
    if(t.at(i)=='r'){
      a += p;
    }else if(t.at(i)=='s'){
      a += r;
    }else{
      a += s;
    }
  }
  
  for(i=k;i<n;i++){
    if(t.at(i)!=t.at(i-k)){
      if(t.at(i)=='r'){
        a += p;
      }else if(t.at(i)=='s'){
        a += r;
      }else{
        a += s;
      }
    }else{
      t.at(i)='n';
    }
  }
  
  cout << a << endl;
}