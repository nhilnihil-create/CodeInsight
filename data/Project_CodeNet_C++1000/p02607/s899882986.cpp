/*==========================================================================*/
/*
    AUTHOR:    BPZ
	CREATED:   10.09.2020 14:52:25

*/
/*--------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int cnt = 0;
  for (int i = 1; i < n + 1; i++) {
  	cin >> a[i];
  	if (i % 2 && a[i] % 2) {
  		cnt++;
  	}
  }
  cout << cnt << '\n';
  return 0;
}
