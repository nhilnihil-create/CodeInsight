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

int binomialmod2(ll a, ll b) {
    if ((b<0) || (b>a)) {  return 0;  }
    int ret = 1;
    while (b>0) {
        int digb = b%2, diga = a%2;
        a/=2; b/=2;
        if (digb>diga) { ret = 0; break; }
    }
    return ret;
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
        readint(n);
        vector<int> a;
        readstring(s);
        for(char c : s) {
            a.push_back(c-'1');
        }

        vector<int> amod2;
        for(int x : a) {
            amod2.push_back(x%2);
        }

        int val = 0;
        forr(i,0,n) {
            val += binomialmod2(n-1, i) * amod2[i];
            val = val % 2;
        }
        if (val==1) {
            cout << 1 << endl; continue;
        }
        bool is_it_zero = false;
        forr(i,0,n) {
            if (a[i]==1) {is_it_zero=true;break;}
        }
        if (is_it_zero) {
            cout << 0 << endl; continue;
        }
        forr(i,0,n) {
            a[i]/=2;
        }
        val = 0;
        forr(i,0,n) {
            int x = binomialmod2(n-1, i);
            if (x==1) {
              val = val ^ a[i];
            }
        }
        cout << 2*val << endl;

    }
 
//    auto end = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
 
    return 0;
}
