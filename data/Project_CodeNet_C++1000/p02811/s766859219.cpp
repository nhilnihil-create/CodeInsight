/**
 * author: moririn_cocoa       
**/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

int main(void) {
  
  int K;
  int X;
  
  cin >> K;
  cin >> X;
  
  if ( X <= 500 * K ) {
    
    cout << "Yes" << endl;
  }
  
  else if ( X > 500 * K ) {
    
    cout << "No" << endl;
  }
  
  return 0;
}
