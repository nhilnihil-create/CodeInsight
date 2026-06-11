#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, sum=0;
  cin >> n >> l;
  int badTaste = l;
  int goodTaste = l+n-1;
  sum=(badTaste+goodTaste)*n/2;
  if(badTaste>0) sum-=badTaste;
  else
  if(goodTaste<0) sum-=goodTaste;
  cout << sum << endl;
}
