#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  
  //cout<<a<<" "<<b<<endl;
  
  int x[2000001];
  for(int i=0; i<=200000; i++ ){
    x[i]=i-100000;
  }
  
  for(int i=b-a+1+100000; i<=a+b-1+100000; i++){
    cout<<x[i]<<" "; 
  
  }
  
}