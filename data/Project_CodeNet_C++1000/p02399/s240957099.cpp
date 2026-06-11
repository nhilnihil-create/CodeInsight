#include<cstdio>
#include<iostream>
using namespace std;

#define ll long long

int main() {
  ll a, b;
  cin >> a >> b;
  printf("%lld %lld %.7f\n", a / b, a % b, (double)a / b);
  return 0;
}
  