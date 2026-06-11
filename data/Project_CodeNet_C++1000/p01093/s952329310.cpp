#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010

bool solve(){
  int n, a[SIZE];
  int ans = INF;
  
  scanf("%d", &n);
  if(n == 0) return false;
  for(int i=0;i<n;i++){
    scanf("%d", a+i);
  }
  sort(a, a+n);
  for(int i=1;i<n;i++)
    ans = min(ans, abs(a[i] - a[i-1]));
  

  printf("%d\n", ans);
  return true;
}

int main(){
  while(solve());
  
  return 0;
}

