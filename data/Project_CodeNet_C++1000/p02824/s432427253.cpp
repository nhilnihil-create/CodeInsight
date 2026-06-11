

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
    cout.precision(17);
    ll modd = 1000 * 1000 * 1000 + 7;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no
    ll infinit = 10000000000000000;


//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(n); readll(m); readll(v); readll(p);

        vector<ll> score;
        forr(i,0,n) {
            readll(kk); score.push_back(kk);
        }
        if (n-p<=0) {
            cout << n << endl;
            break;
        }

        sort(score.begin(), score.end());

        ll ans = binary_search([&score, &p, &m, &v, &n](ll x){
            vector<ll> scores;
            ll max_val = score[x] + m;
            forr(i,0,n) {
                if ((i<n-p+1) && (i!=x)) {
                    scores.push_back(score[i]);
                }
            }
            int v_new = v-(p-1)-1;
            if (v_new <= 0) {
                return (scores.back() <= max_val);
            }
            if (scores.back() > max_val) {
                return false;
            }

            ll filled = 0;
            for(auto s : scores) {
               filled += min(m, max_val-s);
            }
            return (filled >= v_new * m);

        }, 0, n-p);

        cout << n-ans << endl;
    }
    return 0;
}
