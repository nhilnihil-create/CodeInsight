#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

void primeFac(uint64_t n, set<uint64_t>& v) {
    for(uint64_t i=2; i*i <= n; ++i) {
        if(n % i == 0) {
            v.insert(i);
            while(n % i == 0 && n > 0) {
//                cout << n << " / " << i << " = " << n/i << endl;
//                cout << i << " *= ";
                n /= i;
            }
        } 
    }
    if(n!=1) {
        v.insert(n);
    }
}

int main() {
    uint64_t A, B;
    cin >> A >> B;
    set<uint64_t> s1;
    set<uint64_t> s2;
    primeFac(A, s1);
    primeFac(B, s2);

#if 0
    cout << "s1 ";
    for(auto itr: s1) {
        cout << itr <<  ",";
    }
    cout << endl;
    cout << "s2 ";
    for(auto itr: s2) {
        cout << itr <<  ",";
    }
    cout << endl;
#endif

    vector<int> result;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(result));
    cout << result.size() + 1u << endl;

    return 0;
}


