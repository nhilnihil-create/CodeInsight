#include<algorithm>
#include<iostream>
#include<map>
#include <bits/stdc++.h>
#include<cmath>
#define mod 1000000007
#define ll long long 
using namespace std;

int main() {

  ll x,y;
  cin>>x>>y;
  ll yy=x*y/__gcd(x,y);
  cout<<yy<<endl;
	return 0;
}