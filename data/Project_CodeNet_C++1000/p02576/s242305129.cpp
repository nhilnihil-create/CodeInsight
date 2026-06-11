/*==========================================================================*/
/*
    AUTHOR:    BPZ
	CREATED:   30.08.2020 11:02:46

*/
/*--------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, t;
  cin >> n >> x >> t;
  n % x == 0 ? cout << n / x * t << '\n' : cout <<  (n / x + 1) * t << '\n';
  return 0;
}
