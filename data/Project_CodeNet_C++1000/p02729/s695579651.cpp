#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include<string>
using namespace std; 



int main()
{
  long long int n,m,y,p;
  cin>>n>>m;
  // mC2+nC2
  // combinations
  y=n*n+m*m-n-m;
  p=y/2;
  cout<<p;
  
}