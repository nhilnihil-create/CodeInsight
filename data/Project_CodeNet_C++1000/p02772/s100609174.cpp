#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t n,a,b;
  b=0;
  cin>>n;
  for(int64_t i=0;i<n;i++){
  cin>>a;
    if(a%2==0&&a%3!=0&&a%5!=0){b=1;}
    
  }
  if(b==0){cout<<"APPROVED"<<endl;}
  else{cout<<"DENIED"<<endl;}
} 