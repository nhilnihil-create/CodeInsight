#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,s2;
  long long k,n,i,j,p,p2;
  cin >> s >> k;
  n=s.size();
  p=0;
  p2=0;
  j=0;
  
  int a=1;
  for(i=0;i<n-1;i++){
    if(s.at(i)!=s.at(i+1)){
      a=0;
    }
  }
  
  if(a==1){
    cout << n*k/2 << endl;
  }else{
    s2=s+s;
    for(i=0;i<n;i++){
      if(i==n-1){
        p=p+(j+1)/2;
        j=0;
      }else if(s.at(i)!=s.at(i+1)){
        p=p+(j+1)/2;
        j=0;
      }else{
        j++;
      }
    }
    for(i=0;i<n*2;i++){
      if(i==n*2-1){
        p2=p2+(j+1)/2;
        j=0;
      }else if(s2.at(i)!=s2.at(i+1)){
        p2=p2+(j+1)/2;
        j=0;      
      }else{
        j++;
      }
    }
    cout << (k-1)*p2-(k-2)*p << endl;
  }
}