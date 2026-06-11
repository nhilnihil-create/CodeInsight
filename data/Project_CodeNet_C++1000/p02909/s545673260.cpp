#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c;
  string s,t;
  cin >>s;
  if(s[0]=='S')t="Cloudy";
  if(s[0]=='C')t="Rainy";
  if(s[0]=='R')t="Sunny";
  cout <<t;
}