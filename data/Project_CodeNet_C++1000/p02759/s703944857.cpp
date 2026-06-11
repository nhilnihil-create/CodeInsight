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
	
  int N;
  
  cin >> N;
  
  if ( N % 2 == 0 ) {
    
    cout << N / 2 << endl;
  }
  
  else if ( N % 2 == 1 ) {
    
    cout << N / 2 + 1 << endl;
  }

return 0;
}
