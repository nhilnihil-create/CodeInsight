#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a,b,k,r,r1,s;

   cin>>a>>b>>k;

  if(k<=a){
     cout<<a-k<<" "<<b<<endl;
  }
  else if(k<=a+b)
  {
      cout<<"0"<<" "<<b-(k-a)<<endl;
  }
  else{

    cout<<"0"<<" "<<"0"<<endl;
  }

 return 0;
}
