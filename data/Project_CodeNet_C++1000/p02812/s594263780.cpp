///////////////////////////////////////////////////////////////////////////
/*Dis = size of the program || TLE. */
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops") /* D = Too many loops */
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d)                                                              \
  for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
       blockTime.second;                                                       \
       debug("%s: %lld ms\n", d,                                               \
             chrono::duration_cast<chrono::milliseconds>(                      \
                 chrono::high_resolution_clock::now() - blockTime.first)       \
                 .count()),                                                    \
            blockTime.second = false)

int main() {
  time__("Total Execution time is: ") {
    /*Code STARTS here */
    int size;
    cin >> size;

    char str[size];
    cin >> str;
    int count{};
    for (int i = 0; i <= (size-1)-2; i++)
    {
      if(str [i] == 'A' && str [i+1] == 'B' && str [i+2] == 'C')
      {
        count++;
      }

    }
    cout << count << endl;
    
    /*Code ENDS here */
  }
}
