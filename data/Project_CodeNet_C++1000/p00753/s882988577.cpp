#include <bits/stdc++.h>

using namespace std;

int main()
{
  bool isPrime[300001];
  for(int i = 0; i <= 300000; i++) isPrime[i] = true;
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i*i <= 300000; i++){
    if(isPrime[i]){
      for(int j = 2 * i; j <= 300000; j += i) isPrime[j] = false;
    }
  }

  int n;
  while(cin >> n, n){
    int cnt = 0;
    for(int i = n + 1; i <= 2 * n; i++){
      if(isPrime[i]) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}