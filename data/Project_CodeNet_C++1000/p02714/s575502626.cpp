

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

int main()   {
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(n);
        readstring(s);
        map<char,vector<int>> part_sum;

        for (char c1 : vector<char>{'R', 'G', 'B'}) {
          part_sum[c1].push_back(0);
          for(char c : s) {
              part_sum[c1].push_back(part_sum[c1].back() + (c==c1));
          }
        }

        ll ret = 0;
        forr(i,0,s.size()) {
            for(int j = i+1; j < s.size(); j++) {
                if (s[i]!=s[j]) {
                    set<char> pp{'R', 'G', 'B'};
                    pp.erase(s[i]); pp.erase(s[j]);
                    char c_third = *pp.begin();

                    int count_third = part_sum[c_third].back() - part_sum[c_third][j+1];
                    if (j+(j-i) < s.size()) {
                      count_third -= (s[j + (j-i)] == c_third);
                    }
                    ret += count_third;
                }
            }
        }

        cout << ret << endl;
    }
    return 0;
}
