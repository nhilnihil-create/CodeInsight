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
  if(s=="SUN")a=7;
  if(s=="MON")a=6;
  if(s=="TUE")a=5;
  if(s=="WED")a=4;
  if(s=="THU")a=3;
  if(s=="FRI")a=2;
  if(s=="SAT")a=1;
  cout <<a;
}