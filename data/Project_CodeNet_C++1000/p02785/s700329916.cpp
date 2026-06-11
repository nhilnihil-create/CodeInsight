
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

ll modd = 1000*1000*1000+7;

ll binary_search(function<bool(ll)> func, ll start, ll end) {
    /*      func:int ->bool
            returns smallest int x where func(x) evaluates to true, searches in [start,end), it is assumed the values are false, .. , false, true ...
             */
    if (end <= start) {   return end;  }   // has to be here, otherwise func(end-1) in next line could be a problem
    if (!func(end-1)) {  return end;  }
    while (end-start>1) {
        ll mid = (start+end)/2;
        if (func(mid)) {  end = mid;  } else { start = mid;   }
    }
    if (func(start)) {  return start;  } else {  return end;   }
}; 


int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
 
//    auto start = chrono::steady_clock::now();
  
//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(n); readint(k);
        vector<ll> a;
        forr(i,0,n) {
            readll(aa); a.push_back(aa);
        }
        sort(a.begin(), a.end());

        cout << accumulate(a.begin(), a.begin() + max(0LL,n-k), 0LL) << endl;
    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}