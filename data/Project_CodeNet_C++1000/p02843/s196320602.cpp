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
#include <ctype.h>
#include <queue>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    int x; cin >> x;
    int m,d;
    d = x%100;
    m = x/100;

    for(int i = 0; i < m; i ++){
        if(d >= 5) d-= 5;
        else if(d >= 4) d-= 4;
        else if(d >= 3) d-= 3;
        else if(d >= 2) d-= 2;
        else if(d >= 1) d-= 1;
    }

    cout << ((d == 0)?1:0);
    return 0;
}









