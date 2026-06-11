

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

vector<vector<int>> memoization(3, vector<int>(200003, -1));

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
        vector<pair<string, int>> songs;
        forr(i,0,n) {
            readstring(s); readint(d);
            songs.push_back(make_pair(s,d));
        }
        readstring(s);

        int ss = 0;
        forr(i,0,n) {
            if (songs[i].first == s) {
                ss = i;
            }
        }
        ss++;
        int ret = 0;
        for (;ss < songs.size(); ++ss) {
            ret += songs[ss].second;
        }

        cout << ret << endl;

    }
    return 0;
}
