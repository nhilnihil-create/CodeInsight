#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iterator>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))
 
typedef long long ll;

using namespace std;
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  float n;
  cin>>n;

  cout<<ceil(n/2);
  
  return 0;
}