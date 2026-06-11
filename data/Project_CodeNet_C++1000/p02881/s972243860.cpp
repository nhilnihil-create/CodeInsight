#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
  ll N;
  cin >> N;
  ll a,b;
  ll min = N+1;
  for(ll a=1;a<=(ll)sqrt(N)+1;a++){
    if(N%a==0){
      b = N / a;
      if(min > a+b){
        min = a + b;
      }
    }
  }
  ll ans = min -2;
  cout << ans << endl;
}