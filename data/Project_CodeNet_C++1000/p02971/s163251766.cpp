#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() 
{
  ll n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int max = *std::max_element(a.begin(), a.end());
  int max2;

  std::vector<int>::iterator iter = std::max_element(a.begin(), a.end());
  size_t index = std::distance(a.begin(), iter);

  a[index] = 0;
  
  max2 = *std::max_element(a.begin(), a.end());

  rep(i,n){
    if (i == index) {
      cout << max2 << endl;
    }else{
      cout << max << endl;
    }
  }

  return 0;
}
