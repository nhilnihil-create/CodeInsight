

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


int main()   {
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(a); readll(b); readll(m);
        vector<ll> aa;
        forr(i,0,a) {readll(ff); aa.push_back(ff);}
        vector<ll> bb;
        forr(j,0,b) {readll(ff); bb.push_back(ff);}

        vector<tuple<ll,ll,ll>> coupon;

        forr(i,0,m) { readll(x); readll(y); readll(z); coupon.push_back(make_tuple(x,y,z));  }

        ll mina = 10000000, minb = 100000000;
        forr(i,0,a) {  mina = min(mina, aa[i]);   }
        forr(i,0,b) {  minb = min(minb, bb[i]);   }

        ll minc = 100000000;
        forr(i,0,m) {
            minc = min(minc, -get<2>(coupon[i])+aa[get<0>(coupon[i])-1]+bb[get<1>(coupon[i])-1]);
        }

        cout << min(minc, mina+minb) << endl;

    }
    return 0;
}
