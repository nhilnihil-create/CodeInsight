#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll h, w, n;
  cin >> h >> w >> n;
  
  cout << (n + max(h,w)-1) / max(h,w) << endl;

  return 0;
}
