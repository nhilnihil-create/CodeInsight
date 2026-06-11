/*==========================================================================*/
/*
    AUTHOR:    BPZ
	CREATED:   10.09.2020 14:48:36

*/
/*--------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int l, r, d;
  cin >> l >> r >> d;
  int cnt = 0;
 	int start = l / d;
 	if (l % d != 0) {
 		start++;
 	}
  for (int i = start; i * d <= r; i++) {
  	cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
