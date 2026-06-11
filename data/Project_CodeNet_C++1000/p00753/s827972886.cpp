#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

bool is_prime(int x){
  if (x == 1) return false;
  for (int i = 2; i <= sqrt(x); i++){
    if (x % i == 0) return false;
  }
  return true;
}

int main(){
   int n;
   while (cin >> n){
      if (n == 0) return 0;
      int ans = 0;
      for (int i = n+1; i <= 2*n; i++){
         if (is_prime(i)) ans++;
      }
      cout << ans << endl;
   }
}

