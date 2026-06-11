#include<algorithm>
#include<iostream>
#include<map>
#include <bits/stdc++.h>
#include<cmath>
#define mod 1000000007
#define ll long long 
using namespace std;

int main() {


  ll a,b;
  cin>>a>>b;
  if(a==1 && b==2)
  {
  	cout<<3<<endl;
  }
  else if(a==2 && b==1)
  {
  	cout<<3<<endl;
  }
  else if(a==3 && b==2)
  {
  	cout<<1<<endl;
  }
  else if(a==2 && b==3)
  {
  	cout<<1<<endl;
  }
  else if(a==3 && b==1)
  {
  	cout<<2<<endl;
  }else if(a==1 && b==3)
  {
  	cout<<2<<endl;
  }
	return 0;
}