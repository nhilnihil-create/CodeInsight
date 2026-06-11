#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  string s;
  cin >> s;
  if(s=="SUN") cout << '7' << '\n';
  if(s=="MON") cout << '6' << '\n';
  if(s=="TUE") cout << '5' << '\n';
  if(s=="WED") cout << '4' << '\n';
  if(s=="THU") cout << '3' << '\n';
  if(s=="FRI") cout << '2' << '\n';
  if(s=="SAT") cout << '1' << '\n';
  return 0;
}