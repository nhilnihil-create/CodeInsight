#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int k,a,b,flag;
  cin>>k>>a>>b;
  flag=0;
  while(a<=b){
    if(a%k==0){
      flag=1;
    }
    a++;
  }
  if(flag==1){
    cout<<"OK";
  }else{
    cout<<"NG";
  }
}