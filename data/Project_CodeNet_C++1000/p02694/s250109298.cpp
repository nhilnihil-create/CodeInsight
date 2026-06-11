#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
int main() 
{
   long long int t,c=0;
    scanf("%lld",&t);
  long long int yen=100,amt=0;
  while(yen<t)
  {
      ++c;
    yen=yen+(long long int)(yen)/100;
  }
  printf("%lld",c);
}