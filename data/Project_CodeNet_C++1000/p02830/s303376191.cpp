#include<algorithm>
#include<iostream>
#include<map>
#include <bits/stdc++.h>
#include<cmath>
#define mod 1000000007
#define ll long long 
using namespace std;

int main() {

  ll n;
  cin>>n;
  string s1,s2;
  cin>>s1>>s2;
  string s3="";
  ll xx=s1.length();
  for(ll i=0;i<n;i++)
  {
  	s3=s3+s1[i];
  	s3=s3+s2[i];
  }
  cout<<s3<<endl;
	return 0;
}