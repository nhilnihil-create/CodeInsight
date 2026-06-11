#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;

  long long ans = N;
  for(long long i = 1; i <= sqrt(N); ++i) {
    if(N % i == 0) {
      ans = (i - 1) + ((N / i) - 1);
    }
  }

  cout << ans << endl;

  return 0;
}
