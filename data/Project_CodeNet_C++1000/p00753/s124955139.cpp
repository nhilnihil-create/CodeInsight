#include <bits/stdc++.h>

using namespace std;

#define loop(n) for(int lp=0; lp<(n); lp++)
#define ascent(i, a, b)  for(int (i)=(a); (i)<(b); (i)++)
#define descent(i, a, b) for(int (i)=(a); (i)<(b); (i)--)

#define N 300000

int main() {
  int n;
  vector<int> prime;
  bool flg[N];

  memset(flg, true, sizeof(flg));
  flg[0] = flg[1] = false;
  
  ascent(i, 2, N) {
    if(flg[i]) {
      prime.push_back(i);
      
      for(int j = i; j < N; j += i) {
	flg[j] = false;
      }
    }
  }

  while(cin >> n, n) {
    //  cout << *upper_bound(prime.begin(), prime.end(), n) << " " << *upper_bound(prime.begin(), prime.end(), 2*n) <<  " ";

    cout << upper_bound(prime.begin(), prime.end(), 2*n) - upper_bound(prime.begin(), prime.end(), n) << endl;
  }
  return 0;
}