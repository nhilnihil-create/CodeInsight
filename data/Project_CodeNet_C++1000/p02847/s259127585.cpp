#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  cin >> s;
  ll a;
  if(s=="SUN")a=7;
  else if(s=="MON")a=6;
  else if(s=="TUE")a=5;
  else if(s=="WED")a=4;
  else if(s=="THU")a=3;
  else if(s=="FRI")a=2;
  else a=1;
  cout << a << endl;

}