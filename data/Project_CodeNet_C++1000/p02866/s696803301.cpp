
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
typedef long long ll;
 
using namespace std;

ll modd = 998244353;

template<class T>
T fastpower(T a, long long n) {  // n must be >= 1
  if (n % 2 == 0) {  
      T halfpower = fastpower<T>(a, n/2);
      return (halfpower*halfpower) % modd;
  } else {
      if (n == 1) {  return a; } else {  
          T halfpower = fastpower<T>(a, n/2);
          return (((halfpower*halfpower)%modd)*a)%modd;
      }
  }
};

 
int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, 1000);   // rand_gen(rng) gets the rand no
 
//    auto start = chrono::steady_clock::now();
 
//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);
        map<int,int> d;
        bool problem = false;
        forr(i,0,n) {
            readint(kk); d[kk]++;
            if (i==0) {  if (kk!=0) {problem = true;}  }
        }
        if (problem) {cout << 0 << endl; continue;}

        ll ret = 1;
        if (d.begin()->second!=1) { cout << 0 << endl; continue; }
        ll prev = 1, prev_d = 0;
        auto it = next(d.begin());
        while (it != d.end()) {
            if (it->first!=prev_d+1) {  ret = 0; break;  }
            ll how_many = it->second;
            // choose(how_many+prev-1, prev-1)
            ret *= fastpower<ll>(prev, how_many);
            ret = ret % modd;
            prev = it->second; prev_d = it->first; ++it;
        }
        cout << ret << endl;


    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}