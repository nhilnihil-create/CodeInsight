/*==========================================================================*/
/*
    AUTHOR:    BPZ
	CREATED:   30.08.2020 11:06:58

*/
/*--------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 0; i < (int) s.size(); i++) {
  	sum += s[i] - '0';
  }
  sum % 9 == 0 ? cout << "Yes" << '\n' : cout << "No" << '\n';
  return 0;
}
