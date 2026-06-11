#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   
  int n;
  cin>>n;
  float o;
  if(n%2==0){
  	o=n/2;
  }
  
  else{
  	o=n/2+1;
  }
 
  float p=o/n;
  cout<<fixed<<setprecision(6)<<p<<endl;
  
  return 0;
}