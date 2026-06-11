

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
        readint(n); readll(k);
        vector<ll> a;
        multiset<ll> a_set;
        forr(i,0,n) {
            readll(kk); a.push_back(kk);
            a_set.insert(kk);
        }
        map<int,int> how_many_below;
        int so_far = 0;
        while (!a_set.empty()) {
            int smallest = *a_set.begin();
            how_many_below[smallest] = so_far;
            so_far += a_set.count(smallest);
            a_set.erase(smallest);
        }
        vector<int> kleene;
        forr(i,0,a.size()) {
            int ct = 0;
            for(int j = i+1; j < a.size(); ++j) {
                if (a[j]<a[i]) {ct++;}
            }
            kleene.push_back(ct);
        }

        ll ret = 0;
        forr(i,0,a.size()) {
            ret += k*kleene[i];
            ret = ret % modd;
            ret += ((((k*(k-1))/2) % modd) * how_many_below[a[i]]) % modd;
            ret = ret % modd;
        }
        
        cout << ret << endl;
    }
    return 0;
}
