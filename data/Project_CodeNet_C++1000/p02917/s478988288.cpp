#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
\
#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;


int main() {
    int prev;
    int cur;
    int ans =0;
    int n;
    cin >> n;

    if(n == 2){
        cin >> cur;
        cout << 2*cur;
    }else {
        for (int i = 0; i < n - 1; i++) {
            cin >> cur;
            if (i == 0 || i == n - 2) ans += cur;
            if (i != 0) ans += min(prev, cur);

            prev = cur;
        }
        cout << ans;
    }
}





