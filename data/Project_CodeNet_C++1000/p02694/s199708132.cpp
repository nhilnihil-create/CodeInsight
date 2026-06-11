#include<bits/stdc++.h>
using namespace std;
int main(void){
long long n,m=100;cin>>n;
int a=0;
  for(int i=0;i<100000;i++){
    if(m>=n)
        break;
    m+=m/100;
    a++;}
  cout<<a<<endl;
return 0;}
