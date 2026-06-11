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
#include <math.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)



using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    int n,d;
    int x[11][11];
    int ans = 0;
    float val;

    cin >> n >> d;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < d; j ++){
            cin >> x[i][j];
        }
    }

    for(int i = 0; i < n-1; i ++){
        for(int j = i+1; j < n; j ++){
            val = 0;
            for(int k = 0; k <d; k ++) {
                val += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            if(is_integer(sqrtf(val))) ans ++;

        }
    }

    cout << ans;

}





