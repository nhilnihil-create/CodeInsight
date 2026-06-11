#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(int argc, char *argv[]) {
  ll n, i, j;
  cin >> n;

  vector<ll> s(n+1,1LL);
  ll sum = 0LL;
  sum += 1LL;
  
  for(i=2;i<=n;i++){
    for(j=i;j<=n;j+=i){
      s[j] += 1LL;
    }
    sum += i * s[i];
  }

  cout << sum << endl;

  return 0;
}
