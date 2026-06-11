

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

long long gcd(long long a, long long b) { 
    if (a == 0)  {   return b;  }
    return gcd(b % a, a); 
};

class Factorial {
    public:
      ll modd = 1000 * 1000 * 1000 + 7;
      vector<ll> bin;

      Factorial(int n) : bin(n+1, 0) {
          bin[0] = 1;
          forr(i,1,n) {
              bin[i] = i*bin[i-1]; bin[i] = bin[i] % modd;
          }
      }

      ll val(int i) {  return bin[i];  }
};

vector<vector<int>> answer(int n, int colour) {
    if (n==1) { return vector<vector<int>>();  }
    if (n==2) { return vector<vector<int>>(2, vector<int>(2, colour));  }
    vector<vector<int>> ret(n, vector<int>(n));
    forr(i,0,n)  {
        for(int j = i+1; j < n; j++) {
            if (i%2!=j%2) {  ret[i][j] = colour;  }
        }
    }
    vector<vector<int>> ret1 = answer(n/2, colour+1);
    vector<vector<int>> ret2;
    if (n%2==0) {  ret2=ret1;  } else { ret2 = answer(n-n/2, colour+1); }
    forr(i,0,n) {
        for(int j = i+1; j < n; j++) {
            if ((i%2==0) && (j%2==0)) {
                ret[i][j] = ret2[i/2][j/2];                
            }
            if ((i%2==1) && (j%2==1)) {
                ret[i][j] = ret1[(i-1)/2][(j-1)/2];                
            }
        }
    }
    return ret;
};

int main()   {
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n);

        vector<vector<int>> ans = answer(n, 1);

        forr(i,0,n-1) {
            for(int j = i+1; j < n; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
       
    }
    return 0;
}
