#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int64_t N, ans;
  cin >> N;
  ans=0;
  vector<int64_t> a(N);
  for (int i=0; i<N; i++) {
    if ((i+1)%3!=0 && (i+1)%5!=0) {
      a[i]=i+1;
    }
    else {
      a[i]=0;
    }
    ans=ans+a[i];
  }
  cout << ans << endl;
}