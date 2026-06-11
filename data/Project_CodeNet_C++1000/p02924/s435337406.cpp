#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  ll ans=0;
  rep(i,n) ans+=i;
  cout<<ans;   

}