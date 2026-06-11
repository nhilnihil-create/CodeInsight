#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <numeric>
 
using namespace std;

long long quickpow(int n) {
    long long base = 2;
    long long ans = 1;
    while (n) {
        if (n&1) ans *= base;
        n >>= 1;
        base *= base;
    }
    return ans;
}


const long long maxn = 1e6+5;
// long long arr[maxn] = {};

int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    multiset<long long, greater<long long> > s1;
    multiset<long long, greater<long long> > s2;

    // multiset<int, greater<int> > test;
    // test.insert(1);
    // test.insert(2);
    // test.insert(2);
    // test.insert(4);

    // cout << *(test.upper_bound(4)) << endl;

    long long q = quickpow(N);

    long long t;
    for (int i = 1; i <= q; i++) {
        cin >> t;
        s2.insert(t);
        // cout << i << endl;
    }
    // sort(arr+1, arr+q+1, greater<long long>());

    auto ptr = s2.begin();
    s1.insert(*ptr);
    s2.erase(ptr);

    for (int i = 0; i < N; i++) {
        long long c = quickpow(i);
        auto itr1 = s1.begin();
        long long len = s1.size();
        vector<long long> v;
        for (int i = 0; i < len; i++, itr1++) {
        // for (auto itr1 = s1.begin(); itr1 != s1.end(); itr1++) {
            auto itr2 = s2.upper_bound(*itr1);
            // cout << *itr1 << " " << *itr2 << (itr2==s2.end()) << endl;
            if (itr2 == s2.end()) { cout << "No" << endl; return 0; }
            v.push_back(*itr2);
            // s1.insert(*itr2);
            s2.erase(itr2);
        }
        for (long long a : v) {
            s1.insert(a);
        }

    }

    cout << "Yes" << endl;


    // long long c, maxi = arr[1];
    // for (int i = 0; i < N; i++) {
    //     c = quickpow(i);  //2^0, 2^1, 2^2...
    //     for (int j = 1; j <= c; j++) {
    //         cout << j << " " << j+c << endl;
    //         if (arr[j] == arr[j + c]) { cout << "No" << endl; return 0; }
            
    //     }
    // }
    // cout << "Yes" << endl;
    return 0;
}
