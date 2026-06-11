#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int k,a,b;
  cin>>k;
  cin>>a>>b;
  int t=(b/k)*k;
  if(a<=t)
  cout<<"OK\n";
  else
  cout<<"NG\n";
}