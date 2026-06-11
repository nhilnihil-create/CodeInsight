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
#define d double
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll a,b,k;
  cin>>a>>b>>k;
  
  ll n=min(a,k);
  a-=n;
  k-=n;
  
  n=min(b,k);
  b-=n;
  k-=n;
  
  cout<<a<<" "<<b<<endl;
  
  return 0;
}